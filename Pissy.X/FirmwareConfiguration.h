#ifndef FIRMWARE_CONFIGURATION_H
#define	FIRMWARE_CONFIGURATION_H

/* 76psi 2.26V                                                                */
/* 0psi 0.51V                                                                 */
/* 60 PSI 12033                                                               */
/* VOUT = 10 mV/°F × T °F                                                     */
/* 2^10 = 5V                                                                  */

#define ARRAY_SIZE          (32)
#define LOG2_ARRAY_SIZE     (5)
#define VREF                (5)     /* V                                      */
#define PRESSURE_ZERO       (3392)
#define PRESSURE_SCALE      (145)
#define ADC_SIZE            (10) /* bits */
#define TMR1_RELOAD_MSB     (0xC0)
#define TMR1_RELOAD_LSB     (0x00)
#define MINIMUM_PSI_DISPLAY (5)

#endif	/* FIRMWARE_CONFIGURATION_H                                           */

