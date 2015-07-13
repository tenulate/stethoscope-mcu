/* Direct Memory Access functionality */

#include "DMA.h"
#include <xc.h>
#include <stdint.h>

// Allocate memory for Buffer A and Buffer B in DMA memory
uint16_t BufferA[NUM_SAMPLES] __attribute__((space(dma), aligned(32)));
uint16_t BufferB[NUM_SAMPLES] __attribute__((space(dma), aligned(32)));

/*******************************************************************************
 * Initializes DMA Channel 4 to retrieve data from ADC in continuous ping-pong 
 * mode. The ADC determines the data write addresses 
 ******************************************************************************/
void InitDMA4(void)
{
    DMA_ADC_DATA_DIR = PERIPHERAL_TO_DMA;       // TX from ADC to DMA
    DMA_ADC_DATA_TX_SIZE = DMA_WORD;            // transfer 16 bits of data
    DMA_ADC_INTERRUPT_CONDITION = WHEN_ALL_DATA_MOVED;
    DMA_ADC_ADDRESS_MODE = PERIPHERAL_INDIRECT; // ADC takes care of addressing
    DMA_ADC_CH_MODE = CONTINUOUS_PING_PONG;     // 2 buffers to write to

    DMA4PAD = (int)&ADC1BUF0;   // Transfer data from ADC buffer
    DMA4CNT = NUM_SAMPLES-1;    // Raise DMA interrupt after every NUM_SAMPLES
    DMA4REQ = DMA_IRQ_ADC1;     // ADC interrupt selected for DMA IRQ

    // DMA controller needs to know where in DMA memory BufferA and B start
    DMA4STA = __builtin_dmaoffset(BufferA);
    DMA4STB = __builtin_dmaoffset(BufferB);

    // Clear interrupt flag bit and enable DMA4 interrupts
    DMA_ADC_INTERRUPT_FLAG = NO_INTERRUPT;
    DMA_ADC_INTERRUPT = ENABLE_INTERRUPT;
    DMA_ADC_ENABLE;
}

/*******************************************************************************
 * Interrupt Service Routine (ISR) for DMA Channel 4
*******************************************************************************/
unsigned int DMA_buffer = BUFFER_B;
int flag = 0;
void __attribute__((interrupt, no_auto_psv)) _DMA4Interrupt(void)
{
    // Clear interrupt flag
    DMA_ADC_INTERRUPT_FLAG = NO_INTERRUPT;
    // Change the buffer to which we're storing ADC values
    DMA_buffer = !DMA_buffer;
    flag = 1;
}
