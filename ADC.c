#include "ADC.h"
#include <xc.h>

/*******************************************************************************
 * Initialise Analog-to-Digital converter unit
 ******************************************************************************/
void InitADC() 
{
    DISABLE_ADC;    // To change configuration
    
    // Control reg 1
    ADC_WHEN_IDLE = DISCONTINUE;
    DMA_BUFFER_WRITE_ORDER = SCATTER_GATHER;
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
    ADC_BUFFER_FILL_MODE = FIRST_HALF_THEN_SECOND_HALF;
    ADC_ALTERNATE_INPUT = ALWAYS_USE_A;
    
    // Control reg 3
    ADC_CLOCK_SOURCE = SYSTEM_CLOCK;
    ADC_AUTO_SAMPLE_TIMING = 4;    // 4 Tad for sampling 
    ADC_CONVERSION_CLOCK = TAD_EQUAL_32_TCY;
    
    // Control reg 4
    ADC_DMA_BUFFER = ALLOCATE_128_WORD_PER_ANALOG_INPUT;
    
    // Input channel 0 select reg 
    ADC_SAMPLE_A_NEGATIVE_INPUT = NEG_IN_VREFL;
    ADC_SAMPLE_A_POSITIVE_INPUT = POS_IN_AN0;
    
    // Disable ADC interrupts - let DMA take care of it
    CLEAR_ADC_INTERRUPT_FLAG;
    DISABLE_ADC_INTERRUPT;
    
    ENABLE_ADC; 
}
