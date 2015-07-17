#include <xc.h>
#include "DAC.h"

void InitDAC(void)
{
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
  // Turn DAC on
  ENABLE_DAC;
}

void __attribute__((interrupt, no_auto_psv)) _DAC1RInterrupt(void)
{
  IFS4bits.DAC1RIF = 0; // Clear Riht Channel Interrupt Flag
}
