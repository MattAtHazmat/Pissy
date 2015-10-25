#ifndef ADC_H
#define ADC_H

    /**  Section: Included Files */

    #include <xc.h>
    #include <stdint.h>
    #include <stdbool.h>

    /**      Section: Data Types Definitions     */

    /***  result size of an A/D conversion     */

    typedef uint16_t adc_result_t;

    /** ADC Channel Definition */

    typedef enum {
        POTENTIOMETER = 0x00,
        PRESSURE = 0x02,
        TEMPERATURE = 0x04,       
    } adc_channel_t;

    /** Section: ADC Module APIs     */

    void ADC_Initialize(void);
    adc_result_t ADC_GetConversionResult(void);
    void ADC_ISR(void);
    uint16_t GetChannel(adc_channel_t channel);

#endif	
