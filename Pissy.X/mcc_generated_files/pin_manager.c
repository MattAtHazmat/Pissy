#include <xc.h>
#include "pin_manager.h"

/******************************************************************************/

void PIN_MANAGER_Initialize(void) 
{
    LATA = 0x10;
    TRISA = 0xEF;
    ANSELA = 0x2F;
    LATB = 0x00;
    TRISB = 0xF0;
    ANSELB = 0x30;
    WPUB = 0x00;
    LATC = 0x40;
    TRISC = 0x97;
    LATE = 0x00;
    TRISE = 0x08;
    WPUE = 0x00;
    OPTION_REGbits.nWPUEN = 0x01;
    APFCON = 0x00;
}

/******************************************************************************/