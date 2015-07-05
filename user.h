/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* Application specific user parameters used in user.c may go here */
#define OUTPUT_BIT 0
#define INPUT_BIT 1
#define OUTPUT 0x00
#define INPUT 0xFF

#define OFF = 0
#define ON = 1

#define INFINITE_LOOP 1

// UART configs
#define RP7_O RPOR3bits.RP7R
#define U1TX 0b00011

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
void set_LED(int state);