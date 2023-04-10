#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include "soft_i2c.h"
#include "lcd_i2c.h"  

#define SPI_BYTES 8 /* SPI送受信するデーターのバイト数 */
uint8_t data[SPI_BYTES]; // SPI受信格納先
uint8_t send[SPI_BYTES]; // SPI送信格納先
    // send[0] 弾数
    // send[1] 62固定
#define FIRE_MAGA  100 /* 射撃終了直後のマガジン通電回数 */
#define INFIRE_MAX 500 /* in_fire の最大限度 */
uint16_t infire_count; // in_fire の現在持続回数
uint16_t bbini_count; // 発射弾数クリア時のLED点灯回数

uint8_t trig0 = 0; // 旧トリガー状態
uint8_t trig = 0; // トリガー状態
uint8_t maga = 0; // 弾倉ボタン状態
uint16_t num_maga = 0; // マガジン通電カウンター
uint8_t force_maga = 0; // 弾倉強制通電


uint8_t semi_raw; // セミオートスイッチの状態（即値）0:OFF 1:ON
uint8_t semi_now; // セミオートスイッチの状態（安定化処理後)
uint8_t semi_now0; // 直前の semi_now 値
uint8_t in_fire; // 0:主砲通電OFF 1:セミオートスイッチOFF待ち 2:ON待ち
uint8_t in_fire0; // 直前の in_fire 値
uint8_t laser_on; // レーザーを発光させるなら1

#define NUM_ON2OFF 5 /* semi_now がONの状態で semi_raw が連続何回OFFになれば semi_nowをOFFにするか */
#define NUM_OFF2ON 2 /* semi_now がOFFの状態で semi_raw が連続何回ONになれば semi_nowをONにするか */

uint8_t cnt_semi_on; // semi_raw が連続何回ONになったか
uint8_t cnt_semi_off; // semi_raw が連続何回OFFになったか

uint8_t num_now; // 何発目を発射したか
uint8_t num_burst; // 1:セミオート 3:バースト 0:フルオート


// SPI受信
void int_strb(void) {
    uint8_t b, d; //, *dp = data;
    uint8_t m, b2, d2; //, *dp2 = send;
    for (uint8_t idx=0; idx<SPI_BYTES; idx++) {
        d = 0;
//        d2 = (*(dp2++));
        d2 = send[idx];
        m = 0x80;
        for (b=0; b<8; b++) {
            while (SPI_CLOCK_PORT == 0) {} // CLOCK立ち上がりをソフトループで待つ
            if (d2 & m) {
                SPI_OUT_SetHigh();
            }
            else {
                SPI_OUT_SetLow();
            }
            m >>= 1;
            d <<= 1;
            while (SPI_CLOCK_PORT == 1) {} // CLOCK立ち下がりをソフトループで待つ
            d |= SPI_IN_PORT;
        }
//        (*(dp++)) = d;
        data[idx] = d;
    }
    while (SPI_STRB_PORT == 1) {} // STRB立ち下がりを確認
}


// セミオートスイッチ安定化読み込み
void read_semi(void)
{
    if (SEMIAUTO_GetValue() == 0) { // セミオートスイッチが押された
        semi_raw = 1;
        if (cnt_semi_on < 255) {
            cnt_semi_on ++;
        }
        if (cnt_semi_on >= NUM_OFF2ON) {
            semi_now = 1;
        }
        cnt_semi_off = 0;
    }
    else {
        semi_raw = 0;
        if (cnt_semi_off < 255) {
            cnt_semi_off ++;
        }
        if (cnt_semi_off >= NUM_ON2OFF) {
            semi_now = 0;
        }
        cnt_semi_on = 0;
    }
}


// 現在の状態をレーザーのＯＮ・ＯＦＦに反映させる
void show_lazer(void) {
        if (laser_on == 0) { // 基本的に発光させない場合
            PWM2_Stop();
        }
        else { // 基本的に発光させる場合
            if (in_fire) {
                PWM2_PeriodSet(20000); // 高速点滅
                PWM2_DutyCycleSet(5000);
            }
            else {
                PWM2_PeriodSet(60000); // 低速点滅
                PWM2_DutyCycleSet(15000);
            }
            PWM2_LoadBufferSet();        
            PWM2_Start();
        }                
}


// in_fire == 0 へ移行共通処理
void to_in_fire0(void) {
    in_fire = 0;
    num_maga = FIRE_MAGA;           
}


// in_fire == 1 へ移行共通処理
void to_in_fire1(void) {
    in_fire = 1;
    infire_count = 0;
}


// stank_rsv_fire
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    IOCAF0_SetInterruptHandler(int_strb);

    LED_SetHigh();
    
//    char buf[32];
//    __delay_ms(100);    
//    LCD_i2c_init(8);

    in_fire = 0; // 0:主砲通電OFF 1:セミオートスイッチOFF待ち 2:ON待ち
    in_fire0 = 0; // in_fire の直前値
    trig = trig0 = 0;
    cnt_semi_on = cnt_semi_off = 0;
    semi_now = semi_now0 = 2; // 不安定
    num_now = 0;
    num_burst = 1;
    infire_count = 0;
    bbini_count = 0;
    laser_on = 1;
    send[0] = 0;
    send[1] = 62;
    
    // 出力全OFF
    PWM1_DutyCycleSet(0);
    PWM1_LoadBufferSet();
    FIRE_SetLow();
    PWM1_Stop();
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    // セミオートスイッチの状態を確定させる
    while (semi_now == 2) {
        read_semi();
    }

    LED_SetLow();

    while (1) {
        if (bbini_count & 16) {
            LED_SetHigh();
        }
        else {
            LED_SetLow();
        }
        if (bbini_count > 0) {
            bbini_count --;
        }

        if (data[1] & 2) { // TRL-D
            laser_on = 0;
        }
        if (data[1] & 1) { // TRL-U
            laser_on = 1;
        }
        if (SETBB_GetValue() == 0) {
            send[0] = 0; // 弾数クリア
            bbini_count = 200;
        }
        show_lazer();

        maga = 0; // 手動給弾OFF
        trig = data[1];
        if (in_fire == 0) { // 主砲通電OFF中
            FIRE_SetLow();
            if (MAGA_GetValue() == 0) { // 手動給弾ボタン押された
                maga = 1; // 手動給弾ON
            }
            uint8_t trig1 = (trig & (trig ^ trig0));

            if (trig1 & 64) { // X押されている
                // フルオート開始
                num_burst = 0;
                num_now = 0;
                to_in_fire1();
            }
            else if (trig1 & 32) { // B押されている
                // セミオート開始
                num_burst = 1;
                num_now = 0;
                to_in_fire1();
            }
            else if (trig1 & 128) { // A押されている
                // 3点バースト開始
                num_burst = 3;
                num_now = 0;
                to_in_fire1();
            }
        }
        else if (in_fire == 1) { // セミオートスイッチがOFFになるまで待つ
            FIRE_SetHigh();
            infire_count ++;
            if (infire_count >= INFIRE_MAX) { // 通電時間が長過ぎる
                to_in_fire0(); // 強制終了
            }
            read_semi();
            if (semi_now == 0) {
                in_fire = 2;
            }
        }
        else if (in_fire == 2) { // セミオートスイッチがONになるまで待つ
            FIRE_SetHigh();
            infire_count ++;
            if (infire_count >= INFIRE_MAX) { // 通電時間が長過ぎる
                to_in_fire0(); // 強制終了
            }
            read_semi();
            if (semi_now == 1) {
                // 射撃１サイクル完了
                num_now ++;
                if (send[0] < 255) {
                    send[0] ++;
                }
                if (num_burst > 0) { // フルオートではない
                    if (num_now >= num_burst) { // 撃ち終わった
                        to_in_fire0(); // 射撃終了
                    }
                    else {
                        to_in_fire1(); // 次サイクルへ
                    }
                }
                else { // フルオート
                    if (trig & 64) { // X押されてる
                        to_in_fire1(); // 次サイクルへ
                    }
                    else {
                        to_in_fire0(); // 射撃終了
                    }                    
                }
            }
        }
        else {
            in_fire = 0;
        }

        if (in_fire) { // 射撃中のハイパワー給弾
            PWM1_DutyCycleSet(1200);
            PWM1_LoadBufferSet();
            PWM1_Start();
        }
        else if (num_maga > 0) { // 連射終了直後の給弾
            num_maga --;           
            PWM1_DutyCycleSet(600);
            PWM1_LoadBufferSet();
            PWM1_Start();
        }
        else if (maga == 1) { // 手動時のローパワー送弾
            PWM1_DutyCycleSet(500);
            PWM1_LoadBufferSet();
            PWM1_Start();
        }
        else {
            PWM1_Stop();
            PWM1_DutyCycleSet(0);
            PWM1_LoadBufferSet();
        }

        trig0 = trig;
        in_fire0 = in_fire;
        semi_now0 = semi_now;
        __delay_us(500);
    }
}

/**
 End of File
*/