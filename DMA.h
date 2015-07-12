/* MACROS and definitions for Direct Memory Access funcitonality */
#ifndef DMA_H
#define	DMA_H

/******************************************************************************/
/* ADC to DMA SETTINGS                                                        */
/******************************************************************************/
// Using DMA Channel 4 (arbitrarily, could be anything between 0-7)
/* Number of samples to transfer from ADC to DMA before block is 'complete', ie.
   DMA interrupt is raised */
#define NUM_SAMPLES 16
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

/******************************************************************************/
/* DMA Level #define Macros                                                   */
/******************************************************************************/

/* DMAxCON settings */
// Transfer size
#define DMA_BYTE             1
#define DMA_WORD             0
// Transfer direction
#define DMA_TO_PERIPHERAL    1
#define PERIPHERAL_TO_DMA    0
// Block transfer interrupt
#define WHEN_ALL_DATA_MOVED  0
#define WHEN_HALF_DATA_MOVED 1
// Null data write mode
#define NULL_DATA_WRITE      1
#define NORMAL_OPERATION     0
// Address mode
#define PERIPHERAL_INDIRECT  0b10
#define NO_POST_INCREMENT    0b01
#define POST_INCREMENT       0b00
// Channel operating mode
#define ONE_SHOT_PING_PONG   0b11
#define CONTINUOUS_PING_PONG 0b10
#define ONE_SHOT             0b01
#define CONTINUOUS           0b00

/* DMAxREQ settings */
// Transfer data to/from DMA
#define FORCE_DMA_TX 1
#define AUTO_DMA_TX  0
// Peripheral IRQ numbers
#define DMA_IRQ_DAC1_LEFT       0b1001111
#define DMA_IRQ_DAC1_RIGHT      0b1001110
#define DMA_IRQ_ECAN1_TX        0b1000110
#define DMA_IRQ_ECAN1_RX        0b0100010
#define DMA_IRQ_DCI_TX          0b0111100
#define DMA_IRQ_PMP_MASTER_TX   0b0101101
#define DMA_IRQ_SPI2_TX         0b0100001
#define DMA_IRQ_UART1_RX        0b0001011
#define DMA_IRQ_UART2_RX        0b0011110
#define DMA_IRQ_UART2_TX        0b0011111
#define DMA_IRQ_UART1_TX        0b0001100
#define DMA_IRQ_ADC1            0b0001101
#define DMA_IRQ_SPI1_TX         0b0001010
#define DMA_IRQ_TIMER3          0b0001000
#define DMA_IRQ_OC2             0b0000110
#define DMA_IRQ_IC2             0b0000101
#define DMA_IRQ_OC1             0b0000010
#define DMA_IRQ_IC1             0b0000001
#define DMA_IRQ_INT0            0b0000000

/* DMA interrupt flags */
#define NO_INTERRUPT        0
#define INTERRUPT           1
#define ENABLE_INTERRUPT    1
#define DISABLE_INTERRUPT   0

/* DMA buffers */
#define BUFFER_A            0
#define BUFFER_B            1

/******************************************************************************/
/* DMA Function Prototypes                                                    */
/******************************************************************************/
void InitDMA4(void);
void __attribute__((interrupt, no_auto_psv)) _DMA4Interrupt(void);

#endif	/* DMA_H */
