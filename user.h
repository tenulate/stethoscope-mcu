#ifndef USER_H
#define USER_H

// Map MCU pins to logical names
#define LED_PIN             LATBbits.LATB14
#define LED_PIN_DIR         TRISBbits.TRISB14
#define LED_PIN_MODE        AD1PCFGLbits.PCFG10

#define ADC_PIN_DIR         TRISAbits.TRISA0
#define ADC_PIN_MODE        AD1PCFGLbits.PCFG0

// Digital/Analog settings
#define ANALOG              0
#define DIGITAL             1

/* Application specific user parameters used in user.c may go here */
#define OUTPUT              0
#define INPUT               1
#define OFF                 0
#define ON                  1
#define INFINITE_LOOP       1

// LED config
#define TIME_TO_WAIT        150
#define LED_OFF             (LED_PIN = OFF)
#define LED_ON              (LED_PIN = ON)
#define MIN_TIME            25             // min time to flash LED

/*******************************************************************************
 * User Function Prototypes
 ******************************************************************************/

/* User level functions prototypes (i.e. InitApp) go here */

void initApp(void);         // I/O and Peripheral Initialization
unsigned int v2time(unsigned int);  // translate voltage reading to time interval

#endif // USER_H
