
#include <xc.h>
#include "adc.h"
#include "mcc.h"
#include "../FirmwareConfiguration.h"
#include "../main.h"
#include "string.h"

uint16_t pressure[ARRAY_SIZE];
uint16_t temperature[ARRAY_SIZE];
uint16_t potentiometer[ARRAY_SIZE];
uint8_t pressureIndex;
uint8_t temperatureIndex;
uint8_t potentiometerIndex;

/******************************************************************************/
/*  Section: ADC Module APIs */

void ADC_Initialize(void) 
{
    ADCON0 = 0x01;
    // ADFM right; ADNREF VSS; ADPREF VDD; ADCS FOSC/16; 
    ADCON1 = 0xD0;
    ADRESL = 0x00;
    ADRESH = 0x00;
    ADCON0bits.CHS = POTENTIOMETER;
    ADCON0bits.ADON = true;
    PIE1bits.ADIE = true;
    memset(pressure,0,sizeof(pressure));
    memset(temperature,0,sizeof(temperature));
    memset(potentiometer,0,sizeof(potentiometer));
    pressureIndex=0;
    temperatureIndex=0;
    potentiometerIndex=0;
}

/******************************************************************************/

adc_result_t ADC_GetConversionResult(void) 
{
    return ((ADRESH << 8) + ADRESL);
}

/******************************************************************************/

void ADC_ISR(void) {
    uint16_t ADCResult;
    PIR1bits.ADIF = false;
    PIE1bits.ADIE = false;
    ADCResult = ADC_GetConversionResult();
    ADCON0bits.ADON = false;
    switch(ADCON0bits.CHS)
    {
        case POTENTIOMETER:
        {
            potentiometerIndex &= (ARRAY_SIZE-1);
            potentiometer[potentiometerIndex++] = ADCResult;            
            ADCON0bits.CHS = TEMPERATURE;
            break;
        }
        case TEMPERATURE:
        {
            temperatureIndex &= (ARRAY_SIZE-1);
            temperature[temperatureIndex++] = ADCResult;            
            ADCON0bits.CHS = PRESSURE;
            break;
        }
        case PRESSURE:
        {
            pressureIndex &= (ARRAY_SIZE-1); 
            pressure[pressureIndex++] = ADCResult;                       
        }
        default:
        {
            ADCON0bits.CHS = POTENTIOMETER;
            break;
        }
    }
    ADCON0bits.ADON = true;
    TMR4_StartTimer();
}

/******************************************************************************/

uint16_t GetChannel(adc_channel_t channel)
{
    uint16_t value=0;
    uint16_t *pArray;
    uint8_t sampleIndex;
    switch(channel)
    {
        case POTENTIOMETER:
        {
            pArray = &potentiometer;
            break;
        }
        case PRESSURE:
        {
            pArray = &pressure;
            break;
        }
        case TEMPERATURE:
        {
            pArray = &temperature;
            break;
        }
        default:
        {
            return 0;
        }
    }
    /* sum up all the values in the array */
    INTERRUPT_GlobalInterruptDisable();
    for(sampleIndex=0;sampleIndex<ARRAY_SIZE;sampleIndex++)
    {
        value += pArray[sampleIndex];
    }
    INTERRUPT_GlobalInterruptEnable();
    return value;
}

/******************************************************************************/