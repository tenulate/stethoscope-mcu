#include <xc.h>
#include "DAC.h"

void InitDAC(void)
{
  /* Initiate DAC Clock */
  ACLKCONbits.SELACLK  = 0;  // FRC w/ Pll as Clock Source
  ACLKCONbits.AOSCMD   = 0;  // Auxiliary Oscillator Disabled
  ACLKCONbits.ASRCSEL  = 0;  // Auxiliary Oscillator is the Clock Source
  ACLKCONbits.APSTSCLR = 7;  // Fvco/1 = 159.683333 MHz/1

  DAC1STATbits.ROEN = 1;	// Right Channel DAC Output Enabled
  DAC1DFLT          = 0x8000;	// DAC Default value is the minimum
	
  // Sampling Rate Fs = DACCLK/256 = 103 kHz
  DAC1CONbits.DACFDIV = 8;   // DACCLK = ACLK/(DACFDIV + 1): 158.2 MHz/6 = 26.4 MHz

  DAC1CONbits.FORM    = 0;   // Data Format is an unsigned integer
  DAC1CONbits.AMPON   = 0;   // Analog Output Amplifier is enabled during Sleep Mode/Stop-in Idle mode

  DAC1CONbits.DACEN   = 1;   // DAC1 Module Enabled
}

void __attribute__((interrupt, no_auto_psv)) _DAC1RInterrupt(void)
{
  IFS4bits.DAC1RIF = 0; // Clear Riht Channel Interrupt Flag
}
