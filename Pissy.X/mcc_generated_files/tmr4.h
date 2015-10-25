#ifndef _TMR4_H
#define _TMR4_H

/**  Section: Included Files */

#include <stdint.h>
#include <stdbool.h>

    /**      Section: TMR4 APIs     */

    void TMR4_Initialize(void);
    void TMR4_StartTimer(void);
    void TMR4_StopTimer(void);
    void TMR4_WriteTimer(uint8_t timerVal);
    void TMR4_ISR(void);

#endif // _TMR4_H
