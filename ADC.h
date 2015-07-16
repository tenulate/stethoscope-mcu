/* 
 * File:   ADC.h
 * Author: marko
 *
 * Created on 6 July 2015, 4:04 PM
 */

// Defintions for ADC configuration options

#ifndef ADC_H
#define	ADC_H

/*******************************************************************************
 * ADC Interrupt Flags and registers
 * ****************************************************************************/
#define SET_ADC_INTERRUPT_FLAG IFS0bits.AD1IF = 1
#define CLEAR_ADC_INTERRUPT_FLAG IFS0bits.AD1IF = 0
#define ENABLE_ADC_INTERRUPT IEC0bits.AD1IE = 1
#define DISABLE_ADC_INTERRUPT IEC0bits.AD1IE = 0

/*******************************************************************************
 * AD1CON1 Register
 * ****************************************************************************/

// Enabling the ADC module
#define ENABLE_ADC AD1CON1bits.ADON = 1
#define DISABLE_ADC AD1CON1bits.ADON = 0

// What to do when device is in IDLE
#define ADC_WHEN_IDLE AD1CON1bits.ADSIDL
#define DISCONTINUE 1
#define CONTINUE 0

// Direct Memory Access (DMA) Buffer build mode
#define DMA_BUFFER_WRITE_ORDER AD1CON1bits.ADDMABM
#define ORDER_CONVERSION 1
#define SCATTER_GATHER 0

// 10 or 12 bit mode options
#define ADC_NUMBER_BITS AD1CON1bits.AD12B
#define ADC_12_BITS 1
#define ADC_10_BITS 0

// Data format
#define ADC_DATA_FORMAT AD1CON1bits.FORM
#define ADC_UNSIGNED_INT 0b00
#define ADC_SIGNED_INT 0b01
#define ADC_UNSIGNED_FRACT 0b10
#define ADC_SIGNED_FRACT 0b11

// Sample Clock Source - what determines to start converting sample
#define ADC_SAMPLE_CONVERSION_TRIGGER AD1CON1bits.SSRC
#define AUTO_CONVERT 0b111
#define TIMER_5 0b100
#define TIMER_3 0b010
#define INT0_TRANSITION 0b001
#define SOFTWARE 0b000

// Simultaneous sample select
#define ADC_SIMULTANEOUS_SAMP AD1CON1bits.SIMSAM
#define SIMULATANEOUS 1
#define SEQUENTIAL 0

// Sampling autostart
#define ADC_SAMPLING_START AD1CON1bits.ASAM
#define AFTER_LAST_CONVERSION 1
#define WHEN_SAMP_BIT_SET 0


/*******************************************************************************
 * AD1CON2 Register
 * ****************************************************************************/

// Voltage reference selection
#define ADC_VOLTAGE_REF AD1CON2bits.VCFG
#define AVDD_AVSS 0b000
#define VREF_PLUS_AVSS 0b001
#define AVDD_VREF_MINUS 0b010
#define VREF_PLUS_VREF_MINUS 0b011

// Scan inputs
#define ADC_SCAN_INPUTS AD1CON2bits.CSCNA
#define DURING_SAMPLE_A_BIT 1
#define DONT_SCAN 0

// Channel selection
#define ADC_CHANNEL_SELECT AD1CON2bits.CHPS
#define ADC_CH0 0b00
#define ADC_CH01 0b01
#define ADC_CH0123 0b11

// Sample and conversion operation
#define INCREMENT_DMA_ADDRESS_AFTER_N_SAMPLES AD1CON2bits.SMPI  // 4 bits

// Buffer fill mode
#define ADC_BUFFER_FILL_MODE AD1CON2bits.BUFM
#define START_ADDRESS_ALWAYS 0
#define FIRST_HALF_THEN_SECOND_HALF 1

// Alternate input sample mode
#define ADC_ALTERNATE_INPUT AD1CON2bits.ALTS
#define ALWAYS_USE_A 0
#define USE_A_FIRST_THEN_B 1


/*******************************************************************************
 * AD1CON3 Register
 * ****************************************************************************/

// Clock selection
#define ADC_CLOCK_SOURCE AD1CON3bits.ADRC
#define ADC_INTERNAL_RC 1
#define SYSTEM_CLOCK 0

// Auto sample timing
#define ADC_AUTO_SAMPLE_TIMING AD1CON3bits.SAMC

// Conversion clock
#define ADC_CONVERSION_CLOCK AD1CON3bits.ADCS
#define TAD_EQUAL_TCY 0
#define TAD_EQUAL_2_TCY 1
#define TAD_EQUAL_3_TCY 2
#define TAD_EQUAL_4_TCY 3
#define TAD_EQUAL_5_TCY 4
#define TAD_EQUAL_6_TCY 5
#define TAD_EQUAL_7_TCY 6
#define TAD_EQUAL_8_TCY 7
#define TAD_EQUAL_9_TCY 8
#define TAD_EQUAL_10_TCY 9
#define TAD_EQUAL_11_TCY 10
#define TAD_EQUAL_12_TCY 11
#define TAD_EQUAL_13_TCY 12
#define TAD_EQUAL_14_TCY 13
#define TAD_EQUAL_15_TCY 14
#define TAD_EQUAL_16_TCY 15
#define TAD_EQUAL_17_TCY 16
#define TAD_EQUAL_18_TCY 17
#define TAD_EQUAL_19_TCY 18
#define TAD_EQUAL_20_TCY 19
#define TAD_EQUAL_21_TCY 20
#define TAD_EQUAL_22_TCY 21
#define TAD_EQUAL_23_TCY 22
#define TAD_EQUAL_24_TCY 23
#define TAD_EQUAL_25_TCY 24
#define TAD_EQUAL_26_TCY 25
#define TAD_EQUAL_27_TCY 26
#define TAD_EQUAL_28_TCY 27
#define TAD_EQUAL_29_TCY 28
#define TAD_EQUAL_30_TCY 29
#define TAD_EQUAL_31_TCY 30
#define TAD_EQUAL_32_TCY 31
#define TAD_EQUAL_33_TCY 32
#define TAD_EQUAL_34_TCY 33
#define TAD_EQUAL_35_TCY 34
#define TAD_EQUAL_36_TCY 35
#define TAD_EQUAL_37_TCY 36
#define TAD_EQUAL_38_TCY 37
#define TAD_EQUAL_39_TCY 38
#define TAD_EQUAL_40_TCY 39
#define TAD_EQUAL_41_TCY 40
#define TAD_EQUAL_42_TCY 41
#define TAD_EQUAL_43_TCY 42
#define TAD_EQUAL_44_TCY 43
#define TAD_EQUAL_45_TCY 44
#define TAD_EQUAL_46_TCY 45
#define TAD_EQUAL_47_TCY 46
#define TAD_EQUAL_48_TCY 47
#define TAD_EQUAL_49_TCY 48
#define TAD_EQUAL_50_TCY 49
#define TAD_EQUAL_51_TCY 50
#define TAD_EQUAL_52_TCY 51
#define TAD_EQUAL_53_TCY 52
#define TAD_EQUAL_54_TCY 53
#define TAD_EQUAL_55_TCY 54
#define TAD_EQUAL_56_TCY 55
#define TAD_EQUAL_57_TCY 56
#define TAD_EQUAL_58_TCY 57
#define TAD_EQUAL_59_TCY 58
#define TAD_EQUAL_60_TCY 59
#define TAD_EQUAL_61_TCY 60
#define TAD_EQUAL_62_TCY 61
#define TAD_EQUAL_63_TCY 62
#define TAD_EQUAL_64_TCY 63

/******************************************************************************/
/* AD1CON4 Register                                                           */
/******************************************************************************/

// DMA buffer locations per analog input
#define ADC_DMA_BUFFER AD1CON4bits.DMABL
#define ALLOCATE_1_WORD_PER_ANALOG_INPUT 0
#define ALLOCATE_2_WORD_PER_ANALOG_INPUT 1
#define ALLOCATE_4_WORD_PER_ANALOG_INPUT 2
#define ALLOCATE_8_WORD_PER_ANALOG_INPUT 3
#define ALLOCATE_16_WORD_PER_ANALOG_INPUT 4
#define ALLOCATE_32_WORD_PER_ANALOG_INPUT 5
#define ALLOCATE_64_WORD_PER_ANALOG_INPUT 6
#define ALLOCATE_128_WORD_PER_ANALOG_INPUT 7

/******************************************************************************/
/* AD1CHS0 Register                                                           */
/******************************************************************************/

// Negative input select for sample A and B
#define ADC_SAMPLE_A_NEGATIVE_INPUT AD1CHS0bits.CH0NA
#define ADC_SAMPLE_B_NEGATIVE_INPUT AD1CHS0bits.CH0NB
#define NEG_IN_AN1 1
#define NEG_IN_VREFL 0

// Positive input select for sample A and B
#define ADC_SAMPLE_A_POSITIVE_INPUT AD1CHS0bits.CH0SA
#define ADC_SAMPLE_B_POSITIVE_INPUT AD1CHS0bits.CH0SB
#define POS_IN_AN0  0
#define POS_IN_AN1  1
#define POS_IN_AN2  2
#define POS_IN_AN3  3
#define POS_IN_AN4  4
#define POS_IN_AN5  5
#define POS_IN_AN6  6
#define POS_IN_AN7  7
#define POS_IN_AN8  8
#define POS_IN_AN9  9
#define POS_IN_AN10 10
#define POS_IN_AN11 11
#define POS_IN_AN12 12
#define POS_IN_AN13 13
#define POS_IN_AN14 14
#define POS_IN_AN15 15

/******************************************************************************/
/* ADC Function Prototypes                                                    */
/******************************************************************************/

void InitADC(void);         // Analog-to-Digital conversion initialisation

#endif	/* ADC_H */
