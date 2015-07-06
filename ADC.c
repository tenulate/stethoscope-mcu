#include "ADC.h"
#include <xc.h>

void InitADC() 
{
    ADC_NUMBER_BITS = ADC_12_BITS;
    ADC_CHANNEL_SELECT = ADC_CH0;
    ADC_VOLTAGE_REF = AVDD_AVSS;
    ADC_CLOCK_SOURCE = ADC_SYS_CLOCK;
    
    /* TODO: Check this division factor acts as expected (datasheet register) */
    ADC_CLOCK_DIVISION_FACTOR = 16;
    
    AD1PCFGL = 0xFF;
    
}
