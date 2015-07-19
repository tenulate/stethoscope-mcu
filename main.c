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

int main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
    InitADC();
    InitDAC();
    InitDMA4();

    // DMA Buffer variables
    extern uint16_t BufferA[NUM_SAMPLES];
    extern uint16_t BufferB[NUM_SAMPLES];
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
                  /* Have to shift BufferA result 4 bits left b/c ADC stores
                   * data in unsigned int form that ranges from 
                   * 0x0000 to 0x0FFF
                   * While the DAC data takes unsigned ints from
                   * 0x0000 to 0xFFFF
                   */
                  DAC1RDAT = BufferA[i]<<4;
                else
                  DAC1RDAT = BufferB[i]<<4;
            }
            dma_flag = 0;
        }
    }
}
