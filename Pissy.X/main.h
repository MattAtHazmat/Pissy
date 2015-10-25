#ifndef MAIN_H
#define	MAIN_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "LocalTypes.h"

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>
    <p><b>Description:</b></p>
    <p><b>Precondition:</b></p>
    <p><b>Parameters:</b></p>
    <p><b>Returns:</b></p>
    <p><b>Example:</b></p>
    <code>
     </code>
    <p><b>Remarks:</b></p>
 */

uint8_t BCDto7Segment(uint8_t BCD);
bool WriteDisplay(uint8_t number,bool leftDP,bool rightDP);
STATUS_TYPE GetStatus(void);
void FancyLEDs(void);

#endif	/* MAIN_H */

