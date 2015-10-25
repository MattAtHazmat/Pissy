#ifndef _SPI_H
#define _SPI_H

/**  Section: Included Files */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


    /**      Section: SPI Module APIs     */

void SPI_Initialize(void);
uint8_t SPI_Exchange8bit(uint8_t data);


#endif // _SPI_H
