/*******************************************************************************
 * System Level #define Macros
 ******************************************************************************/

// clock settings                 
#define M 65                        // PLL multiplying factor from Fref to Fvco
#define N1 3                        // PLL division from Fin to Fref
#define N2 2                        // PLL division factor from Fvco to Fosc
#define SYS_FREQ    79841667L       // Fosc = Fin*M/N1/N2, Fin = 7.37MHz
#define FCY         SYS_FREQ/2      // Instruction clock frequency
 
/*******************************************************************************
 * System Function Prototypes
 ******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void configureOscillator(void); /* Handles clock switching/osc initialization */
