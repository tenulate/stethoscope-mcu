#include "ADC.h"
#include <xc.h>

void InitADC() 
{
    DISABLE_ADC;    // To change configuration
    
    // Control reg 1
    ADC_WHEN_IDLE = DISCONTINUE;
    DMA_BUFFER_WRITE_ORDER = ORDER_CONVERSION;
    ADC_NUMBER_BITS = ADC_12_BITS;
    ADC_DATA_FORMAT = ADC_UNSIGNED_INT;
    ADC_SAMPLE_CONVERSION_TRIGGER = AUTO_CONVERT;
    ADC_SIMULTANEOUS_SAMP = SEQUENTIAL;
    ADC_SAMPLING_START = AFTER_LAST_CONVERSION;
    
    // Control reg 2
    ADC_VOLTAGE_REF = AVDD_AVSS;
    ADC_SCAN_INPUTS = DONT_SCAN;
    ADC_CHANNEL_SELECT = ADC_CH0;
    INCREMENT_DMA_ADDRESS_AFTER_N_SAMPLES = 0;
    
    // Control reg 3
    ADC_CLOCK_SOURCE = SYSTEM_CLOCK;
    ADC_AUTO_SAMPLE_TIMING = 31;    // 31 Tad 
    ADC_CONVERSION_CLOCK = TAD_EQUAL_32_TCY;
    
    // Control reg 4
    ADC_DMA_BUFFER = ALLOCATE_16_WORD_PER_ANALOG_INPUT;
    
    // TODO: Make MACRO definitions for these
    AD1CHS0bits.CH0NB = 0;  // negative input CHB is Vrefl
    AD1CHS0bits.CH0NA = 0;  // negative input CHA is Vrefl
    AD1CHS0bits.CH0SB = 0;  // positive input CHB is AN0
    AD1CHS0bits.CH0SA = 1;  // positive input CHA is AN1
    AD1CSSLbits.CSS0 = 1;   // AN0 is scanned
    
    ENABLE_ADC; 
}
