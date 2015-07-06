/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

#define SYS_FREQ        40000000L
#define FCY             SYS_FREQ/2
 
/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
