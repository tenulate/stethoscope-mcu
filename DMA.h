/* MACROS and definitions for Direct Memory Access funcitonality */
#ifndef DMA_H
#define	DMA_H

/******************************************************************************
 * ADC to DMA SETTINGS
 ******************************************************************************/
// Using DMA Channel 4 (arbitrarily, could be anything between 0-7)
/* Number of samples to transfer from ADC to DMA before block is 'complete', ie.
   DMA interrupt is raised */
#define NUM_SAMPLES 128

// Enabling/disabling 
#define DMA_ADC_ENABLE              DMA4CONbits.CHEN = 1
#define DMA_ADC_DISABLE             DMA4CONbits.CHEN = 0
// Transfer size
#define DMA_ADC_DATA_TX_SIZE        DMA4CONbits.SIZE
// Transfer direction
#define DMA_ADC_DATA_DIR            DMA4CONbits.DIR
// Block transfer interrupt
#define DMA_ADC_INTERRUPT_CONDITION DMA4CONbits.HALF
// Address mode
#define DMA_ADC_ADDRESS_MODE        DMA4CONbits.AMODE
// Channel operating mode
#define DMA_ADC_CH_MODE             DMA4CONbits.MODE
// Interrupts
#define DMA_ADC_INTERRUPT_FLAG      IFS2bits.DMA4IF
#define DMA_ADC_INTERRUPT           IEC2bits.DMA4IE

/******************************************************************************
 * DMA to DAC SETTINGS
 ******************************************************************************/

// Enabling/disabling
#define DMA_DAC_ENABLE              DMA5CONbits.CHEN = 1
#define DMA_DAC_DISABLE             DMA5CONbits.CHEN = 0
// Transfer size
#define DMA_DAC_DATA_TX_SIZE        DMA5CONbits.SIZE
// Transfer direction
#define DMA_DAC_DATA_DIR            DMA5CONbits.DIR
// Block transfer interrupt
#define DMA_DAC_INTERRUPT_CONDITION DMA5CONbits.HALF
// Address mode
#define DMA_DAC_ADDRESS_MODE        DMA5CONbits.AMODE
// Channel operating mode
#define DMA_DAC_CH_MODE             DMA5CONbits.MODE
// Interrupts
#define DMA_DAC_INTERRUPT_FLAG      IFS3bits.DMA5IF
#define DMA_DAC_INTERRUPT           IEC3bits.DMA5IE

/*******************************************************************************
 * DMA Level #define Macros
 ******************************************************************************/

/* DMAxCON settings */
// Transfer size
#define DMA_BYTE                1
#define DMA_WORD                0
// Transfer direction
#define DMA_TO_PERIPHERAL       1
#define PERIPHERAL_TO_DMA       0
// Block transfer interrupt
#define WHEN_ALL_DATA_MOVED     0
#define WHEN_HALF_DATA_MOVED    1
// Null data write mode
#define NULL_DATA_WRITE         1
#define NORMAL_OPERATION        0
// Address mode
#define PERIPHERAL_INDIRECT     2
#define NO_POST_INCREMENT       1
#define POST_INCREMENT          0
// Channel operating mode
#define ONE_SHOT_PING_PONG      3
#define CONTINUOUS_PING_PONG    2
#define ONE_SHOT                1
#define CONTINUOUS              0

/* DMAxREQ settings */
// Transfer data to/from DMA
#define FORCE_DMA_TX            1
#define AUTO_DMA_TX             0
// Peripheral IRQ numbers
#define DMA_IRQ_DAC1_LEFT       79          // 0b1001111
#define DMA_IRQ_DAC1_RIGHT      78          // 0b1001110
#define DMA_IRQ_ECAN1_TX        70          // 0b1000110
#define DMA_IRQ_ECAN1_RX        34          // 0b0100010
#define DMA_IRQ_DCI_TX          60          // 0b0111100
#define DMA_IRQ_PMP_MASTER_TX   45          // 0b0101101
#define DMA_IRQ_SPI2_TX         33          // 0b0100001
#define DMA_IRQ_UART1_RX        11          // 0b0001011
#define DMA_IRQ_UART2_RX        30          // 0b0011110
#define DMA_IRQ_UART2_TX        31          // 0b0011111
#define DMA_IRQ_UART1_TX        12          // 0b0001100
#define DMA_IRQ_ADC1            13          // 0b0001101
#define DMA_IRQ_SPI1_TX         10          // 0b0001010
#define DMA_IRQ_TIMER3          8           // 0b0001000
#define DMA_IRQ_OC2             6           // 0b0000110
#define DMA_IRQ_IC2             5           // 0b0000101
#define DMA_IRQ_OC1             2           // 0b0000010
#define DMA_IRQ_IC1             1           // 0b0000001
#define DMA_IRQ_INT0            0           // 0b0000000

/* DMA interrupt flags */
#define NO_INTERRUPT            0
#define INTERRUPT               1
#define ENABLE_INTERRUPT        1
#define DISABLE_INTERRUPT       0

/* DMA buffers */
#define BUFFER_A                0
#define BUFFER_B                1

/*******************************************************************************
 * DMA Function Prototypes
 ******************************************************************************/
void InitADC_DMA(void);
void InitDAC_DMA(void);
void __attribute__((interrupt, no_auto_psv)) _DMA4Interrupt(void);
void __attribute__((interrupt, no_auto_psv)) _DMA5Interrupt(void);

#endif	/* DMA_H */
