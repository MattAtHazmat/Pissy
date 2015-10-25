// CONFIG1
#pragma config CLKOUTEN = OFF    // Clock Out Enable->CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable->Fail-Safe Clock Monitor is enabled
#pragma config MCLRE = ON    // MCLR Pin Function Select->MCLR/VPP pin function is MCLR
#ifdef __DEBUG
    #pragma config WDTE = OFF    // Watchdog Timer Enable->WDT disabled
#else
    #pragma config WDTE = ON
#endif
#pragma config CPD = OFF    // Data Memory Code Protection->Data memory code protection is disabled
#pragma config FOSC = INTOSC    // Oscillator Selection->INTOSC oscillator: I/O function on CLKIN pin
#pragma config BOREN = ON    // Brown-out Reset Enable->Brown-out Reset enabled
#pragma config IESO = ON    // Internal/External Switchover->Internal/External Switchover mode is enabled
#ifdef __DEBUG
    #pragma config PWRTE = OFF    // Power-up Timer Enable->PWRT disabled
#else
    #pragma config PWRTE = ON
#endif
#pragma config CP = OFF    // Flash Program Memory Code Protection->Program memory code protection is disabled

// CONFIG2
#pragma config PLLEN = ON    // PLL Enable->4x PLL enabled
#pragma config LVP = OFF    // Low-Voltage Programming Enable->High-voltage on MCLR/VPP must be used for programming
#pragma config WRT = OFF    // Flash Memory Self-Write Protection->Write protection off
#pragma config VCAPEN = OFF    // Voltage Regulator Capacitor Enable->All VCAP pin functionality is disabled
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable->Stack Overflow or Underflow will cause a Reset
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (Vbor), low trip point selected.

#include "mcc.h"

void SYSTEM_Initialize(void) 
{
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    ADC_Initialize();
    SPI_Initialize();
    TMR1_Initialize();
    TMR4_Initialize();
}

void OSCILLATOR_Initialize(void) 
{
    // SCS INTOSC; SPLLEN disabled; IRCF 8MHz_HF; 
    OSCCON = 0x72;
    // LFIOFR disabled; HFIOFL not2percent_acc; OSTS intosc; PLLR disabled; HFIOFS not0.5percent_acc; HFIOFR disabled; MFIOFR disabled; T1OSCR disabled; 
    OSCSTAT = 0x00;
    // TUN 0x0; 
    OSCTUNE = 0x00;
}

