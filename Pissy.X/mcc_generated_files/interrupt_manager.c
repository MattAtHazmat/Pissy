#include "interrupt_manager.h"
#include "mcc.h"

/******************************************************************************/

void interrupt INTERRUPT_InterruptManager(void) 
{
    if (PIE1bits.ADIE && PIR1bits.ADIF) 
    {
        ADC_ISR();
    } 
    else if (PIE1bits.TMR1IE && PIR1bits.TMR1IF) 
    {
        TMR1_ISR();
    }     
    else if (PIE3bits.TMR4IE && PIR3bits.TMR4IF) 
    {
        TMR4_ISR();
    } 
    else 
    {        
    }
}

/******************************************************************************/