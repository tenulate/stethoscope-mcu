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
#include "user.h"            // variables/params used by user.c               
#include <pps.h>             // Make remapping peripherals eaiser

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* Initialize User Ports/Peripherals/Project here */
    
    /* Setup analog functionality and port direction */
    TRISBbits.TRISB12 = OUTPUT_BIT; // Pin 23 output
    /* Initialize peripherals */
    
    // Route UART1 TX through RP7 (pin 16)
//    PPSUnLock;
    PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP7);
//    PPSLock;
}