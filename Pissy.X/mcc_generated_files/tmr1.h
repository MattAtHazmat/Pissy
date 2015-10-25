#ifndef _TMR1_H
#define _TMR1_H

/**  Section: Included Files */

#include <stdbool.h>
#include <stdint.h>

    /**      Section: TMR1 APIs     */

 
    void TMR1_Initialize(void);
    void TMR1_StartTimer(void);
    void TMR1_Reload(void);
    void TMR1_ISR(void);


#endif // _TMR1_H
