/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#include <xc.h>
#include <stdint.h>        /* Includes uint16_t definition                    */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp              */
#include "ADC.h"           /* Analog-to-Digital Conversion functs/params      */
#include "DMA.h"           /* Direct-Memory-Access funct/params               */
#include <libpic30.h>      /* Used for _delay_ms function  - must be included 
                              after FCY has been defined (in system.h) */


/******************************************************************************/
/* Global Variable Declaration                                                */
/******************************************************************************/

/* i.e. uint16_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

int16_t main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize IO ports and peripherals */
    InitApp();
    InitADC();
    InitDMA4();

    // Store ADC reading 
    // Make it static so the Watch variables doesn't show "Out of Scope"
    static uint16_t V_ADC = 0;
    static uint16_t time_to_wait = 0;
    // DMA Buffer variables
    extern uint16_t BufferA[NUM_SAMPLES];
    extern uint16_t BufferB[NUM_SAMPLES];
    extern int dma_flag;
    extern unsigned int DMA_buffer;
    
    while(INFINITE_LOOP)
    {
        if (dma_flag)
        {
            switch (DMA_buffer)
            {
                case BUFFER_A:
                  V_ADC = BufferA[0];
                  break;
                case BUFFER_B:
                  V_ADC = BufferB[0];
                  break;
            }
            
            time_to_wait = v2time(V_ADC);
            LED_OFF;
            __delay_ms(time_to_wait);
            LED_ON;
            __delay_ms(time_to_wait);
            dma_flag = 0;
        }
    }
}
