#include <xc.h>
#include "DAC.h"

void InitDAC(void)
{
  DISABLE_DAC;
  
  // Set up Auxillary clock
  AUX_CLK_SRC = AOSC;
  AUX_CLK_INPUT = PLL_OUTPUT;
  AUX_OSC_MODE = INTERNAL_PLL;
  AUX_CLK_OUTPUT = AUX_IN_DIVIDE_BY_1;
  
  // Set up DAC module
  ENABLE_RIGHT_DAC_CHANNEL;
  DAC_DEFAULT_DATA = 0x0000;
  DAC_CLK = AUX_OUT_DIV_BY_9;
  DAC_DATA_FORMAT = DAC_UNSIGNED_INT;
  DAC_OUTPUT_AMPLIFIER = DAC_DISABLE_WHILE_SLEEP;
  
  // Disable DAC interrupts - let DMA take care of it
  CLEAR_DAC_RIGHT_CH_INTERRUPT_FLAG;
  CLEAR_DAC_LEFT_CH_INTERRUPT_FLAG;
  DISABLE_DAC_RIGHT_CH_INTERRUPT;
  DISABLE_DAC_LEFT_CH_INTERRUPT;
  DAC_RIGHT_INTERRUPT_TYPE = FIFO_EMPTY;
  DAC_LEFT_INTERRUPT_TYPE = FIFO_EMPTY;
  
  // Turn DAC on
  ENABLE_DAC;
}

void __attribute__((interrupt, no_auto_psv)) _DAC1RInterrupt(void)
{
  CLEAR_DAC_RIGHT_CH_INTERRUPT_FLAG;
}
