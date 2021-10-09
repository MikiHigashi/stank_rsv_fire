/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.77
        Device            :  PIC16F1579
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SPI_STRB aliases
#define SPI_STRB_TRIS                 TRISAbits.TRISA0
#define SPI_STRB_LAT                  LATAbits.LATA0
#define SPI_STRB_PORT                 PORTAbits.RA0
#define SPI_STRB_WPU                  WPUAbits.WPUA0
#define SPI_STRB_OD                   ODCONAbits.ODA0
#define SPI_STRB_ANS                  ANSELAbits.ANSA0
#define SPI_STRB_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SPI_STRB_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SPI_STRB_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SPI_STRB_GetValue()           PORTAbits.RA0
#define SPI_STRB_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SPI_STRB_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SPI_STRB_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SPI_STRB_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SPI_STRB_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define SPI_STRB_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define SPI_STRB_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define SPI_STRB_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set SPI_CLOCK aliases
#define SPI_CLOCK_TRIS                 TRISAbits.TRISA1
#define SPI_CLOCK_LAT                  LATAbits.LATA1
#define SPI_CLOCK_PORT                 PORTAbits.RA1
#define SPI_CLOCK_WPU                  WPUAbits.WPUA1
#define SPI_CLOCK_OD                   ODCONAbits.ODA1
#define SPI_CLOCK_ANS                  ANSELAbits.ANSA1
#define SPI_CLOCK_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SPI_CLOCK_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SPI_CLOCK_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SPI_CLOCK_GetValue()           PORTAbits.RA1
#define SPI_CLOCK_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SPI_CLOCK_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SPI_CLOCK_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define SPI_CLOCK_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define SPI_CLOCK_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define SPI_CLOCK_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define SPI_CLOCK_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define SPI_CLOCK_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SPI_IN aliases
#define SPI_IN_TRIS                 TRISAbits.TRISA2
#define SPI_IN_LAT                  LATAbits.LATA2
#define SPI_IN_PORT                 PORTAbits.RA2
#define SPI_IN_WPU                  WPUAbits.WPUA2
#define SPI_IN_OD                   ODCONAbits.ODA2
#define SPI_IN_ANS                  ANSELAbits.ANSA2
#define SPI_IN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SPI_IN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SPI_IN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SPI_IN_GetValue()           PORTAbits.RA2
#define SPI_IN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SPI_IN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SPI_IN_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SPI_IN_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SPI_IN_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define SPI_IN_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define SPI_IN_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SPI_IN_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SEMIAUTO aliases
#define SEMIAUTO_TRIS                 TRISAbits.TRISA3
#define SEMIAUTO_PORT                 PORTAbits.RA3
#define SEMIAUTO_WPU                  WPUAbits.WPUA3
#define SEMIAUTO_GetValue()           PORTAbits.RA3
#define SEMIAUTO_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SEMIAUTO_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SEMIAUTO_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SEMIAUTO_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()              PORTAbits.RA5
#define RA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetPullup()             do { WPUAbits.WPUA5 = 1; } while(0)
#define RA5_ResetPullup()           do { WPUAbits.WPUA5 = 0; } while(0)

// get/set I2C_SCL aliases
#define I2C_SCL_TRIS                 TRISBbits.TRISB6
#define I2C_SCL_LAT                  LATBbits.LATB6
#define I2C_SCL_PORT                 PORTBbits.RB6
#define I2C_SCL_WPU                  WPUBbits.WPUB6
#define I2C_SCL_OD                   ODCONBbits.ODB6
#define I2C_SCL_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define I2C_SCL_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define I2C_SCL_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define I2C_SCL_GetValue()           PORTBbits.RB6
#define I2C_SCL_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define I2C_SCL_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define I2C_SCL_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define I2C_SCL_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define I2C_SCL_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define I2C_SCL_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)

// get/set I2C_SDA aliases
#define I2C_SDA_TRIS                 TRISBbits.TRISB7
#define I2C_SDA_LAT                  LATBbits.LATB7
#define I2C_SDA_PORT                 PORTBbits.RB7
#define I2C_SDA_WPU                  WPUBbits.WPUB7
#define I2C_SDA_OD                   ODCONBbits.ODB7
#define I2C_SDA_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define I2C_SDA_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define I2C_SDA_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define I2C_SDA_GetValue()           PORTBbits.RB7
#define I2C_SDA_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define I2C_SDA_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define I2C_SDA_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define I2C_SDA_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define I2C_SDA_SetPushPull()        do { ODCONBbits.ODB7 = 0; } while(0)
#define I2C_SDA_SetOpenDrain()       do { ODCONBbits.ODB7 = 1; } while(0)

// get/set MAGA aliases
#define MAGA_TRIS                 TRISCbits.TRISC0
#define MAGA_LAT                  LATCbits.LATC0
#define MAGA_PORT                 PORTCbits.RC0
#define MAGA_WPU                  WPUCbits.WPUC0
#define MAGA_OD                   ODCONCbits.ODC0
#define MAGA_ANS                  ANSELCbits.ANSC0
#define MAGA_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define MAGA_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define MAGA_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define MAGA_GetValue()           PORTCbits.RC0
#define MAGA_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define MAGA_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define MAGA_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define MAGA_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define MAGA_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define MAGA_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define MAGA_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define MAGA_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set SETBB aliases
#define SETBB_TRIS                 TRISCbits.TRISC2
#define SETBB_LAT                  LATCbits.LATC2
#define SETBB_PORT                 PORTCbits.RC2
#define SETBB_WPU                  WPUCbits.WPUC2
#define SETBB_OD                   ODCONCbits.ODC2
#define SETBB_ANS                  ANSELCbits.ANSC2
#define SETBB_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SETBB_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SETBB_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SETBB_GetValue()           PORTCbits.RC2
#define SETBB_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SETBB_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SETBB_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SETBB_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SETBB_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define SETBB_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define SETBB_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define SETBB_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC3
#define LED_LAT                  LATCbits.LATC3
#define LED_PORT                 PORTCbits.RC3
#define LED_WPU                  WPUCbits.WPUC3
#define LED_OD                   ODCONCbits.ODC3
#define LED_ANS                  ANSELCbits.ANSC3
#define LED_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_GetValue()           PORTCbits.RC3
#define LED_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set FIRE aliases
#define FIRE_TRIS                 TRISCbits.TRISC4
#define FIRE_LAT                  LATCbits.LATC4
#define FIRE_PORT                 PORTCbits.RC4
#define FIRE_WPU                  WPUCbits.WPUC4
#define FIRE_OD                   ODCONCbits.ODC4
#define FIRE_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define FIRE_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define FIRE_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define FIRE_GetValue()           PORTCbits.RC4
#define FIRE_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define FIRE_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define FIRE_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define FIRE_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define FIRE_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define FIRE_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set SPI_OUT aliases
#define SPI_OUT_TRIS                 TRISCbits.TRISC5
#define SPI_OUT_LAT                  LATCbits.LATC5
#define SPI_OUT_PORT                 PORTCbits.RC5
#define SPI_OUT_WPU                  WPUCbits.WPUC5
#define SPI_OUT_OD                   ODCONCbits.ODC5
#define SPI_OUT_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SPI_OUT_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SPI_OUT_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SPI_OUT_GetValue()           PORTCbits.RC5
#define SPI_OUT_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SPI_OUT_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SPI_OUT_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SPI_OUT_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SPI_OUT_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define SPI_OUT_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF0 pin functionality
 * @Example
    IOCAF0_ISR();
 */
void IOCAF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_InterruptHandler);

*/
extern void (*IOCAF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF0_SetInterruptHandler() method.
    This handler is called every time the IOCAF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF0_SetInterruptHandler(IOCAF0_DefaultInterruptHandler);

*/
void IOCAF0_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/