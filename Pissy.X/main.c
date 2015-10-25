/******************************************************************************/
/*  Main Source File                                                          */
/*                                                                            */
/*  Company:                                                                  */
/*                                                                            */
/*  File Name:                                                                */
/*    main.c                                                                  */
/*                                                                            */
/*  Summary:                                                                  */
/*                                                                            */
/*  Description:                                                              */
/*                                                                            */
/******************************************************************************/

#include "mcc_generated_files/mcc.h"
#include "FirmwareConfiguration.h"
#include "main.h"

/*                         Main application                                   */
STATUS_TYPE systemStatus = {0};

void main(void) 
{   
    adc_channel_t channelDisplaying = TEMPERATURE;
    uint16_t acquiredValue;
    bool rightDecimalPoint=false;
    bool leftDecimalPoint=false;
    uint8_t displayValue=0xFF;
    int32_t value;
    SYSTEM_Initialize();   
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    while (true) 
    {        
        displayValue=0xFF;        
        acquiredValue = GetChannel(channelDisplaying);
        /* what to do with this channel's data and what to display next?      */
        switch(channelDisplaying)
        {
            case PRESSURE:
            {
                value = ((int32_t)acquiredValue)-PRESSURE_ZERO;
                /* make sure value is never negative                          */
                if(value < 0)
                {
                    value=0;
                }
                value = value/PRESSURE_SCALE;
                displayValue = 0xff & value;
                if(displayValue<MINIMUM_PSI_DISPLAY)
                {
                    displayValue = 0;
                }
                rightDecimalPoint = false;
                leftDecimalPoint = false;
                channelDisplaying = TEMPERATURE;                
                break;
            }                
            case TEMPERATURE:
            {                
                value = ((int32_t)acquiredValue*VREF*100)>>(LOG2_ARRAY_SIZE+ADC_SIZE);
                displayValue = 0xff & value;
                rightDecimalPoint = true;
                leftDecimalPoint = false;
                channelDisplaying = PRESSURE;
                break;    
            }
            case POTENTIOMETER:
            {
                value = ((int32_t)acquiredValue*100)>>(LOG2_ARRAY_SIZE+ADC_SIZE);
                displayValue = 0xff & value;
                rightDecimalPoint = true;
                leftDecimalPoint = true;
                channelDisplaying = PRESSURE;
                break;
            }
            default:
            {
                break;
            }
        }
        WriteDisplay(displayValue,leftDecimalPoint,rightDecimalPoint);        
        while(!GetStatus().halfSecond);   
        FancyLEDs();        
        while(GetStatus().halfSecond);
        FancyLEDs();
        #ifndef __DEBUG
            CLRWDT();
        #endif
    }
}

/******************************************************************************/

void FancyLEDs(void)
{
    static uint8_t LEDIncrement=0;
    LEDIncrement &= 0x03;
    switch(LEDIncrement++)
    {
        case 0:
        {
            LED1_Toggle();
            break;
        }
        case 1:
        {
            LED2_Toggle();
            break;
        }
        case 2:
        {
            LED3_Toggle();
            break;
        }
        case 3:
        {
            LED4_Toggle();
            break;
        }
    }
}

/******************************************************************************/

uint8_t BCDto7Segment(uint8_t BCD)
{
    uint8_t segments=0;
    switch(BCD)
    {
        case 0:
        {
            segments=0b01111011;
            break;
        }
        case 1:
        {
            segments=0b01100000;
            break;
        }
        case 2:
        {
            segments=0b01011101;
            break;
        }
        case 3:
        {
            segments=0b01110101;
            break;
        }
        case 4:
        {
            segments=0b01100110;
            break;
        }
        case 5:
        {
            segments=0b00110111;
            break;
        }
        case 6:
        {
            segments=0b00111111;
            break;
        }
        case 7:
        {
            segments=0b01100011;
            break;
        }
        case 8:
        {
            segments=0b01111111;
            break;
        }
        case 9:
        {
            segments=0b01100111;
            break;
        }
    }
    return segments;
}

/******************************************************************************/

bool WriteDisplay(uint8_t number,bool leftDP,bool rightDP)
{
    uint8_t units;
    uint8_t tens;
    if(number < 100)
    {
        tens = number/10;
        units = number - (10*tens);
        DATA_LATCH_SetLow();
        SPI_Exchange8bit(BCDto7Segment(units)|(rightDP<<7));
        if(tens == 0)
        {
            /* blank the leading zero */
            SPI_Exchange8bit(leftDP<<7);
        }
        else
        {
            SPI_Exchange8bit(BCDto7Segment(tens)|(leftDP<<7));
        }
        DATA_LATCH_SetHigh();
        return true;
    }
    else
    {        
        DATA_LATCH_SetLow();
        if(number == 0xFF)
        {
            /* Make the display blank.                                        */
            SPI_Exchange8bit(0);
            SPI_Exchange8bit(0);
        }
        else
        {
            /* overflow: write 99 and set both decimal points                 */
            SPI_Exchange8bit(BCDto7Segment(9)|(1<<7));
            SPI_Exchange8bit(BCDto7Segment(9)|(1<<7));
        }
        DATA_LATCH_SetHigh();
    }
    return false;
}

/******************************************************************************/

STATUS_TYPE GetStatus(void)
{
    STATUS_TYPE tempStatus;
    INTERRUPT_GlobalInterruptDisable();
    tempStatus = systemStatus;
    INTERRUPT_GlobalInterruptEnable();
    return tempStatus;
}

/* End of File ****************************************************************/