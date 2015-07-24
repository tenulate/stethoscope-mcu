/* Device header file */
#include <xc.h>
#include <stdint.h>        // Includes uint16_t definition
#include "system.h"        // System funct/params, like osc/peripheral config
#include "user.h"          // User funct/params, such as InitApp
#include "ADC.h"           // Analog-to-Digital Conversion functs/params
#include "DAC.h"           // Digital-to-Analog Conversion functions
#include "DMA.h"           // Direct-Memory-Access funct/params
#include "FIR.h"           // Filter coefficients
#include <libpic30.h>      /* Used for _delay_ms function  - must be included 
                            * after FCY has been defined (in system.h) */
#include <dsp.h>

int main(void)
{
    /* Configure the oscillator for the device */
    configureOscillator();

    /* Initialize IO ports and peripherals */
    initApp();
    initADC();
    initDAC();
    initADC_DMA();

    // DMA Buffer variables
    extern fractional BufferA[NUM_SAMPLES];
    extern fractional BufferB[NUM_SAMPLES];
    extern int adc_finished;
    extern unsigned int DMA_buffer;
    int i;
    
    // Set up filtering
    extern fractional coefficients[FILTER_ORDER];
    extern fractional xdelay[FILTER_ORDER];
    extern fractional output_signal[NUM_SAMPLES];
    FIRStruct FIRfilter;
    FIRStructInit(&FIRfilter, FILTER_ORDER, coefficients, 0xFF00, xdelay);
    FIRDelayInit(&FIRfilter);
    
    while(INFINITE_LOOP)
    {
        LED_ON;
        if (adc_finished)
        {
            for (i=0; i<NUM_SAMPLES; i++)
            {
                while(!DAC_RIGHT_CH_EMPTY);    // Wait D/A conversion
                    if (DMA_buffer == BUFFER_A)
                    {
                        FIR(NUM_SAMPLES, &output_signal[0], &BufferA[0], &FIRfilter);
                        DAC_RIGHT_CH_OUT = BufferA[i];
                    }
                    else
                    {
                        FIR(NUM_SAMPLES, &output_signal[0], &BufferB[0], &FIRfilter);
                        DAC_RIGHT_CH_OUT = BufferB[i];
                    }
            }
            adc_finished = 0;
        }
    }
}
