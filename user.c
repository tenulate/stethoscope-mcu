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
#include <pps.h>
#include <dsp.h>             // Make remapping peripherals eaiser
#include "user.h"            // variables/params used by user.c

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

// Initialize User Ports/Peripherals
void InitApp(void)
{
    /* Setup analog functionality and port direction */
    LED_PIN_DIR = OUTPUT;   // Pin 23 output
    ADC_PIN_DIR = INPUT;    // Pin 2 input
    ADC_PIN = ANALOG;       // Pin 2 analog
    
    // Route UART1 TX through RP7 (pin 16)
    // PPSUnLock;
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP7);
    // PPSLock;
}

/* Translate voltage reading from ADC to a time interval between MAX/MIN TIME
 * ideally use
 * time = MIN_TIME + (V_ADC-MIN_VADC)*(MAX_TIME-MIN_TIME)/(MAX_VADC-MIN_VADC);
 * But there's issues with rounding off errors when dividing integers
 */
uint16_t v2time(uint16_t Vadc)
{
    uint16_t time = Vadc/8 + MIN_TIME;
    return time;
}
