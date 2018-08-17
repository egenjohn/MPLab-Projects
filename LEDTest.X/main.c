/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F1707
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"

#define BMP280_RETRY_MAX 10

/*=========================================================================
    I2C ADDRESS/BITS/SETTINGS
    -----------------------------------------------------------------------*/
    #define BMP280_ADDRESS                (0x76)
    #define BMP280_CHIPID                 (0x58)
/*=========================================================================*/

/*=========================================================================
    CALIBRATION DATA
    -----------------------------------------------------------------------*/
    typedef struct
    {
      uint16_t dig_T1;
      int16_t  dig_T2;
      int16_t  dig_T3;
/*
      uint16_t dig_P1;
      int16_t  dig_P2;
      int16_t  dig_P3;
      int16_t  dig_P4;
      int16_t  dig_P5;
      int16_t  dig_P6;
      int16_t  dig_P7;
      int16_t  dig_P8;
      int16_t  dig_P9;

      uint8_t  dig_H1;
      int16_t  dig_H2;
      uint8_t  dig_H3;
      int16_t  dig_H4;
      int16_t  dig_H5;
      int8_t   dig_H6;
      */
    } bmp280_calib_data;
    
bmp280_calib_data _bmp280_calib;
int32_t t_fine;

/*=========================================================================*/
/*=========================================================================
    REGISTERS
    -----------------------------------------------------------------------*/
    enum
    {
      BMP280_REGISTER_DIG_T1              = 0x88,
      BMP280_REGISTER_DIG_T2              = 0x8A,
      BMP280_REGISTER_DIG_T3              = 0x8C,

      BMP280_REGISTER_DIG_P1              = 0x8E,
      BMP280_REGISTER_DIG_P2              = 0x90,
      BMP280_REGISTER_DIG_P3              = 0x92,
      BMP280_REGISTER_DIG_P4              = 0x94,
      BMP280_REGISTER_DIG_P5              = 0x96,
      BMP280_REGISTER_DIG_P6              = 0x98,
      BMP280_REGISTER_DIG_P7              = 0x9A,
      BMP280_REGISTER_DIG_P8              = 0x9C,
      BMP280_REGISTER_DIG_P9              = 0x9E,

      BMP280_REGISTER_CHIPID             = 0xD0,
      BMP280_REGISTER_VERSION            = 0xD1,
      BMP280_REGISTER_SOFTRESET          = 0xE0,

      BMP280_REGISTER_CAL26              = 0xE1,  // R calibration stored in 0xE1-0xF0

      BMP280_REGISTER_CONTROL            = 0xF4,
      BMP280_REGISTER_CONFIG             = 0xF5,
      BMP280_REGISTER_PRESSUREDATA       = 0xF7,
      BMP280_REGISTER_TEMPDATA           = 0xFA,
    };

int8_t BMP280_Write8( uint8_t address,
            uint8_t pData)
{
    I2C_MESSAGE_STATUS status;
    uint8_t     writeBuffer[2];
    
    writeBuffer[0] = address;
    writeBuffer[1] = pData;
    
    // write one byte to EEPROM (2 is the count of bytes to write)
    I2C_MasterWrite(   writeBuffer,
                            2,
                            BMP280_ADDRESS,
                            &status);

    // wait for the message to be sent or status has changed.
    while(status == I2C_MESSAGE_PENDING);

    if (status == I2C_MESSAGE_COMPLETE)
        return 0;

    // if status is  I2C_MESSAGE_ADDRESS_NO_ACK,
    //               or I2C_DATA_NO_ACK,
    // The device may be busy and needs more time for the last
    // write so we can retry writing the data, this is why we
    // use a while loop here

    return 0;
}
    
uint8_t BMP280_Read(
                                uint8_t address,
                                uint8_t *pData,
                                uint16_t nCount)
{
    I2C_MESSAGE_STATUS status;
    uint8_t     writeBuffer[3];
    uint16_t    timeOut;
    uint16_t    counter;
    uint8_t     *pD, ret;

    pD = pData;

    for (counter = 0; counter < nCount; counter++)
    {

        // build the write buffer first
        // starting address of the EEPROM memory
        writeBuffer[0] = address;

        // Now it is possible that the slave device will be slow.
        // As a work around on these slaves, the application can
        // retry sending the transaction
        timeOut = 0;
        while(status != I2C_MESSAGE_FAIL)
        {
            // write one byte to EEPROM (2 is the count of bytes to write)
            I2C_MasterWrite(   writeBuffer,
                                    1,
                                    BMP280_ADDRESS,
                                    &status);

            // wait for the message to be sent or status has changed.
            while(status == I2C_MESSAGE_PENDING);

            if (status == I2C_MESSAGE_COMPLETE)
                break;

            // if status is  I2C_MESSAGE_ADDRESS_NO_ACK,
            //               or I2C_DATA_NO_ACK,
            // The device may be busy and needs more time for the last
            // write so we can retry writing the data, this is why we
            // use a while loop here

            // check for max retry and skip this byte
            if (timeOut == BMP280_RETRY_MAX)
                break;
            else
                timeOut++;
        }

        if (status == I2C_MESSAGE_COMPLETE)
        {

            // this portion will read the byte from the memory location.
            timeOut = 0;
            while(status != I2C_MESSAGE_FAIL)
            {
                // write one byte to EEPROM (2 is the count of bytes to write)
                I2C_MasterRead(    pD,
                                        1,
                                        BMP280_ADDRESS,
                                        &status);

                // wait for the message to be sent or status has changed.
                while(status == I2C_MESSAGE_PENDING);

                if (status == I2C_MESSAGE_COMPLETE)
                    break;

                // if status is  I2C_MESSAGE_ADDRESS_NO_ACK,
                //               or I2C_DATA_NO_ACK,
                // The device may be busy and needs more time for the last
                // write so we can retry writing the data, this is why we
                // use a while loop here

                // check for max retry and skip this byte
                if (timeOut == BMP280_RETRY_MAX)
                    break;
                else
                    timeOut++;
            }
        }

        // exit if the last transaction failed
        if (status == I2C_MESSAGE_FAIL)
        {
            ret = 0;
            break;
        }

        pD++;
        address++;

    }
    return (ret);

}

uint8_t BMP280_read8(uint8_t reg)
{
    uint8_t value;

    BMP280_Read( reg, &value, 1 );

    return value;
}

/**************************************************************************/
/*!
    @brief  Reads a 16 bit value over I2C
*/
/**************************************************************************/
uint16_t BMP280_read16(uint8_t reg)
{
    uint16_t value;
    
    BMP280_Read( reg, (uint8_t*)&value, 2 );
    
    return value;
}
#if 0
uint16_t BMP280_read16_LE(uint8_t reg) {
    uint16_t temp = BMP280_read16(reg);
    return (temp >> 8) | (temp << 8);

}
#endif
/**************************************************************************/
/*!
    @brief  Reads a signed 16 bit value over I2C
*/
/**************************************************************************/

int16_t BMP280_readS16(uint8_t reg)
{
    return (int16_t)BMP280_read16(reg);

}
#if 0
int16_t BMP280_readS16_LE(uint8_t reg)
{
    return (int16_t)BMP280_read16_LE(reg);

}
#endif
uint32_t BMP280_read24_le(uint8_t reg)
{
    uint8_t value[3]={0,0,0};
    
    BMP280_Read( reg, value, 3 );
    
    return ((uint32_t)value[0])<<16 | (uint32_t)value[1]<<8 | (uint32_t)value[2];
}

void BMP280_readCoefficients(void)
{
    _bmp280_calib.dig_T1 = BMP280_read16(BMP280_REGISTER_DIG_T1);
    _bmp280_calib.dig_T2 = BMP280_readS16(BMP280_REGISTER_DIG_T2);
    _bmp280_calib.dig_T3 = BMP280_readS16(BMP280_REGISTER_DIG_T3);
#if 0
    _bmp280_calib.dig_P1 = BMP280_read16_LE(BMP280_REGISTER_DIG_P1);
    _bmp280_calib.dig_P2 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P2);
    _bmp280_calib.dig_P3 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P3);
    _bmp280_calib.dig_P4 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P4);
    _bmp280_calib.dig_P5 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P5);
    _bmp280_calib.dig_P6 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P6);
    _bmp280_calib.dig_P7 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P7);
    _bmp280_calib.dig_P8 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P8);
    _bmp280_calib.dig_P9 = BMP280_readS16_LE(BMP280_REGISTER_DIG_P9);
#endif
}

int16_t BMP280_readTemperature(void)
{
    //int32_t var1, var2;
    
    int32_t adc_T = BMP280_read24_le(BMP280_REGISTER_TEMPDATA);
    adc_T >>= 4;
    
    t_fine  = (((((adc_T>>3) - ((int32_t)_bmp280_calib.dig_T1 <<1))) *
                ((int32_t)_bmp280_calib.dig_T2)) >> 11)+
    
                ((((((adc_T>>4) - ((int32_t)_bmp280_calib.dig_T1)) *
                ((adc_T>>4) - ((int32_t)_bmp280_calib.dig_T1))) >> 12) *
                ((int32_t)_bmp280_calib.dig_T3)) >> 14);
    
    //t_fine = var1 + var2;
    
    uint16_t T  = (t_fine * 5 + 128) >> 8;
    return ((T*9)/5)+3200;
}


static uint8_t Decimal = 0b00000001;
static uint8_t Digits[]={
    0b11111100, //0
    0b01100000, //1
    0b11011010, //2
    0b11110010, //3
    0b01100110, //4
    0b10110110, //5
    0b00111110, //6
    0b11100000, //7
    0b11111110, //8
    0b11100110, //9
};
/*
void ShiftClr()
{
    //IO_CLOCK_SetLow();
    IO_OE_SetLow();
    //IO_CLOCK_SetHigh();
    IO_OE_SetHigh();
}
*/
void ShiftOut(uint8_t thisByte)
{
    IO_RCLK_SetLow();
    uint8_t i;
    for(i=0; i<8; i++)
    {
        if( thisByte & (1<<i) )
            IO_DATA_SetHigh();
        else
            IO_DATA_SetLow();
        //__delay_ms(1);
        IO_CLOCK_SetLow();
        //__delay_ms(1);
        IO_CLOCK_SetHigh();
        
    }
    IO_RCLK_SetHigh();
    //__delay_ms(1);
}

void DisplayNum( uint16_t val, uint8_t decPos )
{
    uint8_t i;
    uint8_t outChar;
    for(i=0; i<4; i++)
    {
        switch(i)
        {
            case(3):
                IO_DIG0_SetHigh();
                break;
            case(2):
                IO_DIG1_SetHigh();
                break;
            case(1):
                IO_DIG2_SetLow();
                break;
            default:
                IO_DIG3_SetLow();
                break;
        }
        outChar = Digits[ val % 10];
        if( decPos == i)
            outChar |= Decimal;
        ShiftOut( outChar );
        val = val / 10;
        ShiftOut(0);
        switch(i)
        {
            case(3):
                IO_DIG0_SetLow();
                break;
            case(2):
                IO_DIG1_SetLow();
                break;
            case(1):
                IO_DIG2_SetHigh();
                break;
            default:
                IO_DIG3_SetHigh();
                break;
        }
        
    }
}
uint16_t curTemp;
uint8_t checkTemp;
void TickISR()
{
//    curTemp = BMP280_readTemperature();
    checkTemp=1;
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    I2C_Initialize();
    TMR2_Initialize();
    curTemp=0;
    checkTemp=0;
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    IO_RCLK_SetHigh();
    IO_CLOCK_SetHigh();
    IO_DATA_SetLow();
//    IO_OE_SetHigh();
//    IO_DIG0_SetLow();
//    IO_DIG1_SetLow();
//    IO_DIG2_SetLow();
//    IO_DIG3_SetLow();
    
    uint8_t chipId = BMP280_read8(BMP280_REGISTER_CHIPID);
    if( chipId != BMP280_CHIPID || BMP280_Write8( BMP280_REGISTER_CONTROL, 0x3f) != 0 )
    {
        while(1){DisplayNum(6660,0xf);};
    }
    BMP280_readCoefficients();
    
    curTemp = 0;

    TMR2_SetInterruptHandler( TickISR );
    TMR2_StartTimer();
    
    while (1)
    {
        //DisplayNum(1234+addVal);
        if(checkTemp)
        {
            curTemp = BMP280_readTemperature();
            checkTemp=0;
        }
        if( curTemp > 9999 )
            DisplayNum(curTemp/10, 1);
        else
            DisplayNum(curTemp, 2);
    }
}
/**
 End of File
*/