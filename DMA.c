/* Direct Memory Access functionality */

#include "DMA.h"
#include <xc.h>
#include <stdint.h>

// Allocate memory for Buffer A and Buffer B in DMA memory
uint16_t BufferA[NUM_SAMPLES] __attribute__((space(dma), aligned(256)));
uint16_t BufferB[NUM_SAMPLES] __attribute__((space(dma), aligned(256)));

/*******************************************************************************
 * Initialise DMA Channel 4 to retrieve data from ADC in continuous ping-pong
 * mode
 ******************************************************************************/
void InitADC_DMA(void)
{
    DMA_ADC_DATA_DIR = PERIPHERAL_TO_DMA;       // TX from ADC to DMA
    DMA_ADC_DATA_TX_SIZE = DMA_WORD;            // transfer 16 bits of data
    DMA_ADC_INTERRUPT_CONDITION = WHEN_ALL_DATA_MOVED;
    DMA_ADC_ADDRESS_MODE = POST_INCREMENT;      // DMA takes care of addressing
    DMA_ADC_CH_MODE = CONTINUOUS_PING_PONG;     // 2 buffers to write to

    DMA4PAD = (volatile unsigned int)&ADC1BUF0; // Transfer data from ADC buffer
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
 ******************************************************************************/
unsigned int DMA_buffer = BUFFER_B;
int dma_flag = 0;
void __attribute__((interrupt, no_auto_psv)) _DMA4Interrupt(void)
{
    // Clear interrupt flag
    DMA_ADC_INTERRUPT_FLAG = NO_INTERRUPT;
    // Change the buffer to which we're storing ADC values
    if (DMA_buffer == BUFFER_A)
      DMA_buffer = BUFFER_B;
    else
      DMA_buffer = BUFFER_A;
    dma_flag = 1;
}

/*******************************************************************************
 * Initialise DMA Channel 5 to transfer data from memory to DAC Right channel
 * peripheral
 * Don't bother with this!
 *  couldn't get it working with ADC DMA (Marko 20/07/2015)
 ******************************************************************************/
void InitDAC_DMA(void)
{
    DMA_DAC_DATA_DIR = DMA_TO_PERIPHERAL;       // TX from ADC to DMA
    DMA_DAC_DATA_TX_SIZE = DMA_WORD;            // transfer 16 bits of data
    DMA_DAC_INTERRUPT_CONDITION = WHEN_ALL_DATA_MOVED;
    DMA_DAC_ADDRESS_MODE = POST_INCREMENT;      // DMA takes care of addressing
    DMA_DAC_CH_MODE = CONTINUOUS_PING_PONG;     // 2 buffers to write to

    DMA5PAD = (volatile unsigned int)&DAC1RDAT; // Transfer data to DAC FIFO
    DMA5CNT = NUM_SAMPLES-1;      // Raise DMA interrupt after every NUM_SAMPLES
    DMA5REQ = DMA_IRQ_DAC1_RIGHT; // DAC interrupt selected for DMA IRQ

    // DMA controller needs to know where in DMA memory BufferA and B start
    DMA5STA = __builtin_dmaoffset(BufferB);
    DMA5STB = __builtin_dmaoffset(BufferA);

    // Clear interrupt flag bit and enable DMA4 interrupts
    DMA_DAC_INTERRUPT_FLAG = NO_INTERRUPT;
    DMA_DAC_INTERRUPT = ENABLE_INTERRUPT;
    DMA_DAC_ENABLE;
}

/*******************************************************************************
 * Interrupt Service Routine (ISR) for DMA Channel 5
 ******************************************************************************/
void __attribute__((interrupt, no_auto_psv)) _DMA5Interrupt(void)
{
    // Clear interrupt flag
    DMA_DAC_INTERRUPT_FLAG = NO_INTERRUPT;
}
