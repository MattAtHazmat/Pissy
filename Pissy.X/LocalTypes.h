
#ifndef LOCAL_TYPES_H
#define	LOCAL_TYPES_H

#include <xc.h> 

typedef union {
    uint16_t u;
    int16_t s;
    struct {
        uint8_t LSB;
        uint8_t MSB;
    };
}uint16_b;

typedef union {
    uint8_t w;
    struct {
        unsigned halfSecond:1;
    };
}STATUS_TYPE;

#endif	/* LOCAL_TYPES_H */

