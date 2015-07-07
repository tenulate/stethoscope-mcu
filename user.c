/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          // For uint16_t definition                       
#include <stdbool.h>         // For true/false definition                                    
#include <pps.h>             // Make remapping peripherals eaiser
#include "user.h"            // variables/params used by user.c

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void InitApp(void)
{
    /* Initialize User Ports/Peripherals */
    
    /* Setup analog functionality and port direction */
    LED_PIN_DIR = OUTPUT;   // Pin 23 output
    ADC_PIN_DIR = INPUT;    // Pin 2 input
    ADC_PIN = ANALOG;       // Pin 2 analog
    
    // Route UART1 TX through RP7 (pin 16)
    // PPSUnLock;
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP7);
    // PPSLock;
}
