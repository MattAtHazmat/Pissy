/*  Section: Included Files */

#include <xc.h>
#include "tmr4.h"

/******************************************************************************/

void TMR4_Initialize(void) 
{
    T4CON = 0x13;
    PR4 = 0xFF;
    TMR4_StartTimer();
}

/******************************************************************************/

void TMR4_StartTimer(void) 
{
    TMR4=0;
    PIR3bits.TMR4IF = false;
    PIE3bits.TMR4IE = true;
    T4CONbits.TMR4ON = true;
}

/******************************************************************************/

void TMR4_StopTimer(void) 
{
    T4CONbits.TMR4ON = false;
    PIE3bits.TMR4IE = false;
}

/******************************************************************************/

void TMR4_WriteTimer(uint8_t timerVal) 
{
    TMR4 = timerVal;
}

/******************************************************************************/

void TMR4_ISR(void) 
{
    TMR4_StopTimer();
    PIR1bits.ADIF = false;
    PIE1bits.ADIE = true;
    ADCON0bits.GO_nDONE = true;    
}

/******************************************************************************/