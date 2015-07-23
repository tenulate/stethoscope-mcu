#include <xc.h>
#include <pps.h>
#include "user.h"            // variables/params used by user.c

/*******************************************************************************
 * Initialize User Ports/Peripherals
*******************************************************************************/
void initApp(void)
{
    /* Setup analog functionality and port direction */
    LED_PIN_MODE = DIGITAL; // Pin 25 is digital
    LED_PIN_DIR = OUTPUT;   // Pin 23 output
    ADC_PIN_DIR = INPUT;    // Pin 2 input
    ADC_PIN_MODE = ANALOG;  // Pin 2 analog
    
    // Route UART1 TX through RP7 (pin 16)
    // PPSUnLock;
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP7);
    // PPSLock;
}

/*******************************************************************************
 * Translate voltage reading from ADC to a time interval between MAX/MIN TIME
 * ideally use
 * time = MIN_TIME + (V_ADC-MIN_VADC)*(MAX_TIME-MIN_TIME)/(MAX_VADC-MIN_VADC);
 * But there's issues with rounding off errors when dividing integers
*******************************************************************************/
unsigned int v2time(unsigned int Vadc)
{
    unsigned int time = Vadc/8 + MIN_TIME;
    return time;
}
