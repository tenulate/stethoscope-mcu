/*******************************************************************************
 * System Level #define Macros
 ******************************************************************************/

// clock settings                 
#define M 40                        // PLL multiplying factor from Fref to Fvco
#define N1 2                        // PLL division from Fin to Fref
#define N2 2                        // PLL division factor from Fvco to Fosc
#define FOSC        73728000L       // Fosc = Fin*M/N1/N2, Fin = 7.3728MHz
#define FCY         (FOSC/2)    // Instruction clock frequency

// Fvco = Fref*M/N1 = 7.3728 MHz * 40/2 = 147.456 MHz
// Fosc = Fref*M/N1/N2 = 7.3728 MHz * 40/2/2 = 73.728 MHz
// Fcy = Fosc/2 = 73.728 MHz / 2 = 36.864 MHz

/*******************************************************************************
 * System Function Prototypes
 ******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void configureOscillator(void); /* Handles clock switching/osc initialization */
