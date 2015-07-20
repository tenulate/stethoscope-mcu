/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#include <xc.h>
#include <stdint.h>          /* For uint16_t definition                       */
#include "system.h"          /* variables/params used by system.c             */

/******************************************************************************/
/* System Level Functions                                                     */
/*                                                                            */
/* Custom oscillator configuration funtions, reset source evaluation          */
/* functions, and other non-peripheral microcontroller initialization         */
/* functions get placed in system.c.                                          */
/*                                                                            */
/******************************************************************************/

/* Refer to the device Family Reference Manual Oscillator section for
information about available oscillator configurations.  Typically
this would involve configuring the oscillator tuning register or clock
switching useing the compiler's __builtin_write_OSCCON functions.
Refer to the C Compiler for PIC24 MCUs and dsPIC DSCs User Guide in the
compiler installation directory /doc folder for documentation on the
__builtin functions.*/

void configureOscillator(void)
{
    /* Disable Watch Dog Timer */
    RCONbits.SWDTEN = 0;
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBDbits.PLLDIV = M-2;        // PLL multiplying factor from Fref to Fvco
    CLKDIVbits.PLLPOST = N2/2-1;    // PLL division factor from Fvco to Fosc
    CLKDIVbits.PLLPRE= N1-2;        // PLL division from Fin to Fref
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(OSCCON | 0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while(OSCCONbits.LOCK!=1) {};
}
