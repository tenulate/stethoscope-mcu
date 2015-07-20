/* Device header file */
#include <xc.h>
#include <stdint.h>        // Includes uint16_t definition
#include "system.h"        // System funct/params, like osc/peripheral config
#include "user.h"          // User funct/params, such as InitApp
#include "ADC.h"           // Analog-to-Digital Conversion functs/params
#include "DAC.h"           // Digital-to-Analog Conversion functions
#include "DMA.h"           // Direct-Memory-Access funct/params
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
    extern int dma_flag;
    extern unsigned int DMA_buffer;
    int i;
    
    while(INFINITE_LOOP)
    {
        if (dma_flag)
        {
            for (i=0; i<NUM_SAMPLES; i++)
            {
                while(DAC1STATbits.REMPTY != 1);    // Wait D/A conversion
                    if (DMA_buffer == BUFFER_A)
                        DAC1RDAT = BufferA[i];
                    else
                        DAC1RDAT = BufferB[i];
            }
            dma_flag = 0;
        }
    }
}
