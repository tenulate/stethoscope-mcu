/* 
 * File:   ADC.h
 * Author: marko
 *
 * Created on 6 July 2015, 4:04 PM
 */

// Defintions for ADC configuration options

#ifndef ADC_H
#define	ADC_H

// 10 or 12 bit mode options
#define ADC_NUMBER_BITS AD1CON1bits.AD12B
#define ADC_12_BITS 1
#define ADC_10_BITS 0

// Channel selection
#define ADC_CHANNEL_SELECT AD1CON2bits.CHPS
#define ADC_CH0 0b00
#define ADC_CH01 0b01
#define ADC_CH0123 0b11

// Voltage reference selection
#define ADC_VOLTAGE_REF AD1CON2bits.VCFG
#define AVDD_AVSS 0b000
#define VREF_PLUS_AVSS 0b001
#define AVDD_VREF_MINUS 0b010
#define VREF_PLUS_VREF_MINUS 0b011

// Clock selection
#define ADC_CLOCK_SOURCE AD1CON3bits.ADRC
#define ADC_INTERNAL_RC 1
#define ADC_SYS_CLOCK 0

// ADC clock division from instruction clock
// Must be set to an 8 bit number
#define ADC_CLOCK_DIVISION_FACTOR AD1CON3bits.ADCS

// Data format
#define ADC_DATA_FORMAT AD1CON1bits.FORM
#define ADC_UNSIGNED_INT 0b00
#define ADC_SIGNED_INT 0b01
#define ADC_UNSIGNED_FRACT 0b10
#define ADC_SIGNED_FRACT 0b11

// Enabling the ADC module
#define ENABLE_ADC AD1CON1bits.ADON = 1
#define DISABLE_ADC AD1CON1bits.ADON = 0


/******************************************************************************/
/* ADC Function Prototypes                                                    */
/******************************************************************************/

void InitADC(void);         // Analog-to-Digital conversion initialisation

#endif	/* ADC_H */

