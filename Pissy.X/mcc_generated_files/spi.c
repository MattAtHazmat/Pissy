/**  Section: Included Files */

#include <xc.h>
#include "spi.h"

/**  Section: Macro Declarations */

#define SPI_RX_IN_PROGRESS 0x0

/**  Section: Module APIs */

void SPI_Initialize(void) 
{
    // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP Sample At Middle; UA dontupdate; CKE Idle to Active; D_nA lastbyte_address; 
    SSPSTAT = 0x00;
    // SSPEN enabled; WCOL no_collision; CKP Idle:Low, Active:High; SSPM0 FOSC/64; SSPOV no_overflow; 
    SSPCON1 = 0x22;
    // SSPADD 0; 
    SSPADD = 0x00;
}

uint8_t SPI_Exchange8bit(uint8_t data) 
{
    SSPCON1bits.WCOL = 0;
    SSPBUF = data;
    while (SSPSTATbits.BF == SPI_RX_IN_PROGRESS) {
    }
    return (SSPBUF);
}


