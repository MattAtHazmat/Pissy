#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POTENTIOMETER aliases
#define POTENTIOMETER_TRIS               TRISA0
#define POTENTIOMETER_LAT                LATA0
#define POTENTIOMETER_PORT               RA0
#define POTENTIOMETER_ANS                ANSA0
#define POTENTIOMETER_SetHigh()    do { LATA0 = 1; } while(0)
#define POTENTIOMETER_SetLow()   do { LATA0 = 0; } while(0)
#define POTENTIOMETER_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define POTENTIOMETER_GetValue()         RA0
#define POTENTIOMETER_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define POTENTIOMETER_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define POTENTIOMETER_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define POTENTIOMETER_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set PRESSURE aliases
#define PRESSURE_TRIS               TRISA3
#define PRESSURE_LAT                LATA3
#define PRESSURE_PORT               RA3
#define PRESSURE_ANS                ANSA3
#define PRESSURE_SetHigh()    do { LATA3 = 1; } while(0)
#define PRESSURE_SetLow()   do { LATA3 = 0; } while(0)
#define PRESSURE_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define PRESSURE_GetValue()         RA3
#define PRESSURE_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define PRESSURE_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define PRESSURE_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define PRESSURE_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set TEMP_SENSOR_VDD aliases
#define TEMP_SENSOR_VDD_TRIS               TRISA4
#define TEMP_SENSOR_VDD_LAT                LATA4
#define TEMP_SENSOR_VDD_PORT               RA4
#define TEMP_SENSOR_VDD_ANS                ANSA4
#define TEMP_SENSOR_VDD_SetHigh()    do { LATA4 = 1; } while(0)
#define TEMP_SENSOR_VDD_SetLow()   do { LATA4 = 0; } while(0)
#define TEMP_SENSOR_VDD_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define TEMP_SENSOR_VDD_GetValue()         RA4
#define TEMP_SENSOR_VDD_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define TEMP_SENSOR_VDD_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

#define TEMP_SENSOR_VDD_SetAnalogMode()   do { ANSA4 = 1; } while(0)
#define TEMP_SENSOR_VDD_SetDigitalMode()   do { ANSA4 = 0; } while(0)
// get/set TEMPERATURE aliases
#define TEMPERATURE_TRIS               TRISA5
#define TEMPERATURE_LAT                LATA5
#define TEMPERATURE_PORT               RA5
#define TEMPERATURE_ANS                ANSA5
#define TEMPERATURE_SetHigh()    do { LATA5 = 1; } while(0)
#define TEMPERATURE_SetLow()   do { LATA5 = 0; } while(0)
#define TEMPERATURE_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define TEMPERATURE_GetValue()         RA5
#define TEMPERATURE_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define TEMPERATURE_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define TEMPERATURE_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define TEMPERATURE_SetDigitalMode()   do { ANSA5 = 0; } while(0)
// get/set LED1 aliases
#define LED1_TRIS               TRISB0
#define LED1_LAT                LATB0
#define LED1_PORT               RB0
#define LED1_WPU                WPUB0
#define LED1_ANS                ANSB0
#define LED1_SetHigh()    do { LATB0 = 1; } while(0)
#define LED1_SetLow()   do { LATB0 = 0; } while(0)
#define LED1_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define LED1_GetValue()         RB0
#define LED1_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define LED1_SetPullup()    do { WPUB0 = 1; } while(0)
#define LED1_ResetPullup()   do { WPUB0 = 0; } while(0)
#define LED1_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define LED1_SetDigitalMode()   do { ANSB0 = 0; } while(0)
// get/set LED2 aliases
#define LED2_TRIS               TRISB1
#define LED2_LAT                LATB1
#define LED2_PORT               RB1
#define LED2_WPU                WPUB1
#define LED2_ANS                ANSB1
#define LED2_SetHigh()    do { LATB1 = 1; } while(0)
#define LED2_SetLow()   do { LATB1 = 0; } while(0)
#define LED2_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define LED2_GetValue()         RB1
#define LED2_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define LED2_SetPullup()    do { WPUB1 = 1; } while(0)
#define LED2_ResetPullup()   do { WPUB1 = 0; } while(0)
#define LED2_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define LED2_SetDigitalMode()   do { ANSB1 = 0; } while(0)
// get/set LED3 aliases
#define LED3_TRIS               TRISB2
#define LED3_LAT                LATB2
#define LED3_PORT               RB2
#define LED3_WPU                WPUB2
#define LED3_ANS                ANSB2
#define LED3_SetHigh()    do { LATB2 = 1; } while(0)
#define LED3_SetLow()   do { LATB2 = 0; } while(0)
#define LED3_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define LED3_GetValue()         RB2
#define LED3_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define LED3_SetPullup()    do { WPUB2 = 1; } while(0)
#define LED3_ResetPullup()   do { WPUB2 = 0; } while(0)
#define LED3_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define LED3_SetDigitalMode()   do { ANSB2 = 0; } while(0)
// get/set LED4 aliases
#define LED4_TRIS               TRISB3
#define LED4_LAT                LATB3
#define LED4_PORT               RB3
#define LED4_WPU                WPUB3
#define LED4_ANS                ANSB3
#define LED4_SetHigh()    do { LATB3 = 1; } while(0)
#define LED4_SetLow()   do { LATB3 = 0; } while(0)
#define LED4_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define LED4_GetValue()         RB3
#define LED4_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define LED4_SetPullup()    do { WPUB3 = 1; } while(0)
#define LED4_ResetPullup()   do { WPUB3 = 0; } while(0)
#define LED4_SetAnalogMode()   do { ANSB3 = 1; } while(0)
#define LED4_SetDigitalMode()   do { ANSB3 = 0; } while(0)
// get/set T1OSO aliases
#define T1OSO_TRIS               TRISC0
#define T1OSO_LAT                LATC0
#define T1OSO_PORT               RC0
#define T1OSO_SetHigh()    do { LATC0 = 1; } while(0)
#define T1OSO_SetLow()   do { LATC0 = 0; } while(0)
#define T1OSO_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define T1OSO_GetValue()         RC0
#define T1OSO_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define T1OSO_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set T1OSI aliases
#define T1OSI_TRIS               TRISC1
#define T1OSI_LAT                LATC1
#define T1OSI_PORT               RC1
#define T1OSI_SetHigh()    do { LATC1 = 1; } while(0)
#define T1OSI_SetLow()   do { LATC1 = 0; } while(0)
#define T1OSI_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define T1OSI_GetValue()         RC1
#define T1OSI_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define T1OSI_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS               TRISC3
#define SCK_LAT                LATC3
#define SCK_PORT               RC3
#define SCK_SetHigh()    do { LATC3 = 1; } while(0)
#define SCK_SetLow()   do { LATC3 = 0; } while(0)
#define SCK_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SCK_GetValue()         RC3
#define SCK_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

// get/set SDI aliases
#define SDI_TRIS               TRISC4
#define SDI_LAT                LATC4
#define SDI_PORT               RC4
#define SDI_SetHigh()    do { LATC4 = 1; } while(0)
#define SDI_SetLow()   do { LATC4 = 0; } while(0)
#define SDI_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SDI_GetValue()         RC4
#define SDI_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS               TRISC5
#define SDO_LAT                LATC5
#define SDO_PORT               RC5
#define SDO_SetHigh()    do { LATC5 = 1; } while(0)
#define SDO_SetLow()   do { LATC5 = 0; } while(0)
#define SDO_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define SDO_GetValue()         RC5
#define SDO_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

// get/set DATA_LATCH aliases
#define DATA_LATCH_TRIS               TRISC6
#define DATA_LATCH_LAT                LATC6
#define DATA_LATCH_PORT               RC6
#define DATA_LATCH_SetHigh()    do { LATC6 = 1; } while(0)
#define DATA_LATCH_SetLow()   do { LATC6 = 0; } while(0)
#define DATA_LATCH_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define DATA_LATCH_GetValue()         RC6
#define DATA_LATCH_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define DATA_LATCH_SetDigitalOutput()   do { TRISC6 = 0; } while(0)


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    GPIO and peripheral I/O initialization
 * @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H
/**
 End of File
 */