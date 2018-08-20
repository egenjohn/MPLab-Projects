/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.26.7
        Device            :  PIC16F1707
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB4 procedures
#define RB4_SetHigh()    do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()   do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()   do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()         PORTBbits.RB4
#define RB4_SetDigitalInput()   do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()  do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()     do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()   do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode() do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()    do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()   do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()   do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()         PORTBbits.RB6
#define RB6_SetDigitalInput()   do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()  do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()     do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()   do { WPUBbits.WPUB6 = 0; } while(0)

// get/set IO_RCLK aliases
#define IO_RCLK_TRIS               TRISCbits.TRISC0
#define IO_RCLK_LAT                LATCbits.LATC0
#define IO_RCLK_PORT               PORTCbits.RC0
#define IO_RCLK_WPU                WPUCbits.WPUC0
#define IO_RCLK_OD                ODCONCbits.ODC0
#define IO_RCLK_ANS                ANSELCbits.ANSC0
#define IO_RCLK_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RCLK_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RCLK_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RCLK_GetValue()           PORTCbits.RC0
#define IO_RCLK_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RCLK_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RCLK_SetPullup()      do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RCLK_ResetPullup()    do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RCLK_SetPushPull()    do { ODCONCbits.ODC0 = 1; } while(0)
#define IO_RCLK_SetOpenDrain()   do { ODCONCbits.ODC0 = 0; } while(0)
#define IO_RCLK_SetAnalogMode()  do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_RCLK_SetDigitalMode() do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_CLOCK aliases
#define IO_CLOCK_TRIS               TRISCbits.TRISC1
#define IO_CLOCK_LAT                LATCbits.LATC1
#define IO_CLOCK_PORT               PORTCbits.RC1
#define IO_CLOCK_WPU                WPUCbits.WPUC1
#define IO_CLOCK_OD                ODCONCbits.ODC1
#define IO_CLOCK_ANS                ANSELCbits.ANSC1
#define IO_CLOCK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_CLOCK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_CLOCK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_CLOCK_GetValue()           PORTCbits.RC1
#define IO_CLOCK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_CLOCK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_CLOCK_SetPullup()      do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_CLOCK_ResetPullup()    do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_CLOCK_SetPushPull()    do { ODCONCbits.ODC1 = 1; } while(0)
#define IO_CLOCK_SetOpenDrain()   do { ODCONCbits.ODC1 = 0; } while(0)
#define IO_CLOCK_SetAnalogMode()  do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_CLOCK_SetDigitalMode() do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_DATA aliases
#define IO_DATA_TRIS               TRISCbits.TRISC2
#define IO_DATA_LAT                LATCbits.LATC2
#define IO_DATA_PORT               PORTCbits.RC2
#define IO_DATA_WPU                WPUCbits.WPUC2
#define IO_DATA_OD                ODCONCbits.ODC2
#define IO_DATA_ANS                ANSELCbits.ANSC2
#define IO_DATA_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_DATA_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_DATA_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_DATA_GetValue()           PORTCbits.RC2
#define IO_DATA_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_DATA_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_DATA_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_DATA_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_DATA_SetPushPull()    do { ODCONCbits.ODC2 = 1; } while(0)
#define IO_DATA_SetOpenDrain()   do { ODCONCbits.ODC2 = 0; } while(0)
#define IO_DATA_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_DATA_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

#ifdef BREADBOARD
// get/set IO_DIG0 aliases
#define IO_DIG0_TRIS               TRISCbits.TRISC3
#define IO_DIG0_LAT                LATCbits.LATC3
#define IO_DIG0_PORT               PORTCbits.RC3
#define IO_DIG0_WPU                WPUCbits.WPUC3
#define IO_DIG0_OD                ODCONCbits.ODC3
#define IO_DIG0_ANS                ANSELCbits.ANSC3
#define IO_DIG0_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_DIG0_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_DIG0_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_DIG0_GetValue()           PORTCbits.RC3
#define IO_DIG0_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_DIG0_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_DIG0_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_DIG0_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_DIG0_SetPushPull()    do { ODCONCbits.ODC3 = 1; } while(0)
#define IO_DIG0_SetOpenDrain()   do { ODCONCbits.ODC3 = 0; } while(0)
#define IO_DIG0_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_DIG0_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_DIG1 aliases
#define IO_DIG1_TRIS               TRISCbits.TRISC4
#define IO_DIG1_LAT                LATCbits.LATC4
#define IO_DIG1_PORT               PORTCbits.RC4
#define IO_DIG1_WPU                WPUCbits.WPUC4
#define IO_DIG1_OD                ODCONCbits.ODC4
#define IO_DIG1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_DIG1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_DIG1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_DIG1_GetValue()           PORTCbits.RC4
#define IO_DIG1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_DIG1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_DIG1_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_DIG1_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_DIG1_SetPushPull()    do { ODCONCbits.ODC4 = 1; } while(0)
#define IO_DIG1_SetOpenDrain()   do { ODCONCbits.ODC4 = 0; } while(0)

// get/set IO_DIG2 aliases
#define IO_DIG2_TRIS               TRISCbits.TRISC5
#define IO_DIG2_LAT                LATCbits.LATC5
#define IO_DIG2_PORT               PORTCbits.RC5
#define IO_DIG2_WPU                WPUCbits.WPUC5
#define IO_DIG2_OD                ODCONCbits.ODC5
#define IO_DIG2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_DIG2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_DIG2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_DIG2_GetValue()           PORTCbits.RC5
#define IO_DIG2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_DIG2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_DIG2_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_DIG2_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_DIG2_SetPushPull()    do { ODCONCbits.ODC5 = 1; } while(0)
#define IO_DIG2_SetOpenDrain()   do { ODCONCbits.ODC5 = 0; } while(0)

// get/set IO_DIG3 aliases
#define IO_DIG3_TRIS               TRISCbits.TRISC6
#define IO_DIG3_LAT                LATCbits.LATC6
#define IO_DIG3_PORT               PORTCbits.RC6
#define IO_DIG3_WPU                WPUCbits.WPUC6
#define IO_DIG3_OD                ODCONCbits.ODC6
#define IO_DIG3_ANS                ANSELCbits.ANSC6
#define IO_DIG3_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_DIG3_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_DIG3_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_DIG3_GetValue()           PORTCbits.RC6
#define IO_DIG3_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_DIG3_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_DIG3_SetPullup()      do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_DIG3_ResetPullup()    do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_DIG3_SetPushPull()    do { ODCONCbits.ODC6 = 1; } while(0)
#define IO_DIG3_SetOpenDrain()   do { ODCONCbits.ODC6 = 0; } while(0)
#define IO_DIG3_SetAnalogMode()  do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_DIG3_SetDigitalMode() do { ANSELCbits.ANSC6 = 0; } while(0)
#else
// get/set IO_DIG0 aliases
#define IO_DIG0_TRIS               TRISCbits.TRISC5
#define IO_DIG0_LAT                LATCbits.LATC5
#define IO_DIG0_PORT               PORTCbits.RC5
#define IO_DIG0_WPU                WPUCbits.WPUC5
#define IO_DIG0_OD                ODCONCbits.ODC5
#define IO_DIG0_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_DIG0_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_DIG0_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_DIG0_GetValue()           PORTCbits.RC5
#define IO_DIG0_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_DIG0_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_DIG0_SetPullup()      do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_DIG0_ResetPullup()    do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_DIG0_SetPushPull()    do { ODCONCbits.ODC5 = 1; } while(0)
#define IO_DIG0_SetOpenDrain()   do { ODCONCbits.ODC5 = 0; } while(0)

// get/set IO_DIG1 aliases
#define IO_DIG1_TRIS               TRISCbits.TRISC3
#define IO_DIG1_LAT                LATCbits.LATC3
#define IO_DIG1_PORT               PORTCbits.RC3
#define IO_DIG1_WPU                WPUCbits.WPUC3
#define IO_DIG1_OD                ODCONCbits.ODC3
#define IO_DIG1_ANS                ANSELCbits.ANSC3
#define IO_DIG1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_DIG1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_DIG1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_DIG1_GetValue()           PORTCbits.RC3
#define IO_DIG1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_DIG1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_DIG1_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_DIG1_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_DIG1_SetPushPull()    do { ODCONCbits.ODC3 = 1; } while(0)
#define IO_DIG1_SetOpenDrain()   do { ODCONCbits.ODC3 = 0; } while(0)
#define IO_DIG1_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_DIG1_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_DIG2 aliases
#define IO_DIG2_TRIS               TRISCbits.TRISC6
#define IO_DIG2_LAT                LATCbits.LATC6
#define IO_DIG2_PORT               PORTCbits.RC6
#define IO_DIG2_WPU                WPUCbits.WPUC6
#define IO_DIG2_OD                ODCONCbits.ODC6
#define IO_DIG2_ANS                ANSELCbits.ANSC6
#define IO_DIG2_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_DIG2_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_DIG2_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_DIG2_GetValue()           PORTCbits.RC6
#define IO_DIG2_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_DIG2_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_DIG2_SetPullup()      do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_DIG2_ResetPullup()    do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_DIG2_SetPushPull()    do { ODCONCbits.ODC6 = 1; } while(0)
#define IO_DIG2_SetOpenDrain()   do { ODCONCbits.ODC6 = 0; } while(0)
#define IO_DIG2_SetAnalogMode()  do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_DIG2_SetDigitalMode() do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_DIG3 aliases
#define IO_DIG3_TRIS               TRISCbits.TRISC4
#define IO_DIG3_LAT                LATCbits.LATC4
#define IO_DIG3_PORT               PORTCbits.RC4
#define IO_DIG3_WPU                WPUCbits.WPUC4
#define IO_DIG3_OD                ODCONCbits.ODC4
#define IO_DIG3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_DIG3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_DIG3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_DIG3_GetValue()           PORTCbits.RC4
#define IO_DIG3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_DIG3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_DIG3_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_DIG3_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_DIG3_SetPushPull()    do { ODCONCbits.ODC4 = 1; } while(0)
#define IO_DIG3_SetOpenDrain()   do { ODCONCbits.ODC4 = 0; } while(0)
#endif //BREADBOARD

// get/set IO_OE aliases
#define IO_OE_TRIS               TRISCbits.TRISC7
#define IO_OE_LAT                LATCbits.LATC7
#define IO_OE_PORT               PORTCbits.RC7
#define IO_OE_WPU                WPUCbits.WPUC7
#define IO_OE_OD                ODCONCbits.ODC7
#define IO_OE_ANS                ANSELCbits.ANSC7
#define IO_OE_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_OE_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_OE_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_OE_GetValue()           PORTCbits.RC7
#define IO_OE_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_OE_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_OE_SetPullup()      do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_OE_ResetPullup()    do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_OE_SetPushPull()    do { ODCONCbits.ODC7 = 1; } while(0)
#define IO_OE_SetOpenDrain()   do { ODCONCbits.ODC7 = 0; } while(0)
#define IO_OE_SetAnalogMode()  do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_OE_SetDigitalMode() do { ANSELCbits.ANSC7 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/