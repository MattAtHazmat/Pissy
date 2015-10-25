#include <xc.h>
#include "../FirmwareConfiguration.h"
#include "pin_manager.h"
#include "tmr1.h"
#include "../main.h"

extern STATUS_TYPE systemStatus;

/******************************************************************************/

/*  Section: TMR1 APIs */

void TMR1_Initialize(void) {
    //T1CKPS 1:1; TMR1CS External; T1OSCEN enabled; nT1SYNC do_not_synchronize; TMR1ON disabled; 
    T1CON = 0x8C;
    //T1GTM disabled; T1GGO done; T1GPOL low; T1GVAL disabled; TMR1GE disabled; T1GSS T1G; T1GSPM disabled; 
    T1GCON = 0x00;
    TMR1H = TMR1_RELOAD_MSB;
    TMR1L = TMR1_RELOAD_LSB;
    PIR1bits.TMR1IF = false;
    PIE1bits.TMR1IE = true;
    TMR1_StartTimer();
}

/******************************************************************************/

void TMR1_StartTimer(void) 
{
    T1CONbits.TMR1ON = true;
}

/******************************************************************************/

void TMR1_Reload(void) 
{
    TMR1H = TMR1_RELOAD_MSB;
    TMR1L = TMR1_RELOAD_LSB;
}

/******************************************************************************/

void TMR1_ISR(void) 
{
    PIR1bits.TMR1IF = false;
    TMR1_Reload();
    systemStatus.halfSecond ^= 1;    
}

/******************************************************************************/
