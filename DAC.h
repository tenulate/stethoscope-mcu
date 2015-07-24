#ifndef DAC_H
#define	DAC_H

/*******************************************************************************
 * Auxilary clock register (ACLKCON)
 ******************************************************************************/ 

// Input into Auxillary divider
#define AUX_CLK_INPUT           ACLKCONbits.SELACLK
#define AUX_PIN                 1
#define PLL_OUTPUT              0

// Auxillary osc mode
#define AUX_OSC_MODE            ACLKCONbits.AOSCMD
#define EXTERNAL_CLOCK          3
#define CRYSTAL                 2
#define HIGH_SPEED_OSC          1
#define INTERNAL_PLL            0

// Auxillary clock output divider
#define AUX_CLK_OUTPUT          ACLKCONbits.APSTSCLR
#define AUX_IN_DIVIDE_BY_1      7
#define AUX_IN_DIVIDE_BY_2      6
#define AUX_IN_DIVIDE_BY_4      5
#define AUX_IN_DIVIDE_BY_8      4
#define AUX_IN_DIVIDE_BY_16     3
#define AUX_IN_DIVIDE_BY_32     2
#define AUX_IN_DIVIDE_BY_64     1
#define AUX_IN_DIVIDE_BY_256    4

// Select reference clock
#define AUX_CLK_SRC             ACLKCONbits.ASRCSEL
#define POSC                    1
#define AOSC                    0

/*******************************************************************************
 * DAC1 Control Register (DAC1CON)
 ******************************************************************************/

// Enable/Disable DAC module
#define ENABLE_DAC              DAC1CONbits.DACEN = 1
#define DISABLE_DAC             DAC1CONbits.DACEN = 0

// Idle settings
#define DAC_WHEN_IDLE           DAC1CONbits.DACSIDL
#define DAC_DISCONTINUE         1
#define DAC_CONTINUE            0

// Output amplifier
#define DAC_OUTPUT_AMPLIFIER    DAC1CONbits.AMPON
#define DAC_ENABLE_WHILE_SLEEP  1
#define DAC_DISABLE_WHILE_SLEEP 0

// Data format
#define DAC_DATA_FORMAT         DAC1CONbits.FORM
#define DAC_SIGNED_INT          1
#define DAC_UNSIGNED_INT        0

// Clock divider
#define DAC_CLK                 DAC1CONbits.DACFDIV
#define AUX_OUT_DIV_BY_1		0
#define AUX_OUT_DIV_BY_2		1
#define AUX_OUT_DIV_BY_3		2
#define AUX_OUT_DIV_BY_4		3
#define AUX_OUT_DIV_BY_5		4
#define AUX_OUT_DIV_BY_6		5
#define AUX_OUT_DIV_BY_7		6
#define AUX_OUT_DIV_BY_8		7
#define AUX_OUT_DIV_BY_9		8
#define AUX_OUT_DIV_BY_10		9
#define AUX_OUT_DIV_BY_11		10
#define AUX_OUT_DIV_BY_12		11
#define AUX_OUT_DIV_BY_13		12
#define AUX_OUT_DIV_BY_14		13
#define AUX_OUT_DIV_BY_15		14
#define AUX_OUT_DIV_BY_16		15
#define AUX_OUT_DIV_BY_17		16
#define AUX_OUT_DIV_BY_18		17
#define AUX_OUT_DIV_BY_19		18
#define AUX_OUT_DIV_BY_20		19
#define AUX_OUT_DIV_BY_21		20
#define AUX_OUT_DIV_BY_22		21
#define AUX_OUT_DIV_BY_23		22
#define AUX_OUT_DIV_BY_24		23
#define AUX_OUT_DIV_BY_25		24
#define AUX_OUT_DIV_BY_26		25
#define AUX_OUT_DIV_BY_27		26
#define AUX_OUT_DIV_BY_28		27
#define AUX_OUT_DIV_BY_29		28
#define AUX_OUT_DIV_BY_30		29
#define AUX_OUT_DIV_BY_31		30
#define AUX_OUT_DIV_BY_32		31
#define AUX_OUT_DIV_BY_33		32
#define AUX_OUT_DIV_BY_34		33
#define AUX_OUT_DIV_BY_35		34
#define AUX_OUT_DIV_BY_36		35
#define AUX_OUT_DIV_BY_37		36
#define AUX_OUT_DIV_BY_38		37
#define AUX_OUT_DIV_BY_39		38
#define AUX_OUT_DIV_BY_40		39
#define AUX_OUT_DIV_BY_41		40
#define AUX_OUT_DIV_BY_42		41
#define AUX_OUT_DIV_BY_43		42
#define AUX_OUT_DIV_BY_44		43
#define AUX_OUT_DIV_BY_45		44
#define AUX_OUT_DIV_BY_46		45
#define AUX_OUT_DIV_BY_47		46
#define AUX_OUT_DIV_BY_48		47
#define AUX_OUT_DIV_BY_49		48
#define AUX_OUT_DIV_BY_50		49
#define AUX_OUT_DIV_BY_51		50
#define AUX_OUT_DIV_BY_52		51
#define AUX_OUT_DIV_BY_53		52
#define AUX_OUT_DIV_BY_54		53
#define AUX_OUT_DIV_BY_55		54
#define AUX_OUT_DIV_BY_56		55
#define AUX_OUT_DIV_BY_57		56
#define AUX_OUT_DIV_BY_58		57
#define AUX_OUT_DIV_BY_59		58
#define AUX_OUT_DIV_BY_60		59
#define AUX_OUT_DIV_BY_61		60
#define AUX_OUT_DIV_BY_62		61
#define AUX_OUT_DIV_BY_63		62
#define AUX_OUT_DIV_BY_64		63
#define AUX_OUT_DIV_BY_65		64
#define AUX_OUT_DIV_BY_66		65
#define AUX_OUT_DIV_BY_67		66
#define AUX_OUT_DIV_BY_68		67
#define AUX_OUT_DIV_BY_69		68
#define AUX_OUT_DIV_BY_70		69
#define AUX_OUT_DIV_BY_71		70
#define AUX_OUT_DIV_BY_72		71
#define AUX_OUT_DIV_BY_73		72
#define AUX_OUT_DIV_BY_74		73
#define AUX_OUT_DIV_BY_75		74
#define AUX_OUT_DIV_BY_76		75
#define AUX_OUT_DIV_BY_77		76
#define AUX_OUT_DIV_BY_78		77
#define AUX_OUT_DIV_BY_79		78
#define AUX_OUT_DIV_BY_80		79
#define AUX_OUT_DIV_BY_81		80
#define AUX_OUT_DIV_BY_82		81
#define AUX_OUT_DIV_BY_83		82
#define AUX_OUT_DIV_BY_84		83
#define AUX_OUT_DIV_BY_85		84
#define AUX_OUT_DIV_BY_86		85
#define AUX_OUT_DIV_BY_87		86
#define AUX_OUT_DIV_BY_88		87
#define AUX_OUT_DIV_BY_89		88
#define AUX_OUT_DIV_BY_90		89
#define AUX_OUT_DIV_BY_91		90
#define AUX_OUT_DIV_BY_92		91
#define AUX_OUT_DIV_BY_93		92
#define AUX_OUT_DIV_BY_94		93
#define AUX_OUT_DIV_BY_95		94
#define AUX_OUT_DIV_BY_96		95
#define AUX_OUT_DIV_BY_97		96
#define AUX_OUT_DIV_BY_98		97
#define AUX_OUT_DIV_BY_99		98
#define AUX_OUT_DIV_BY_100		99
#define AUX_OUT_DIV_BY_101		100
#define AUX_OUT_DIV_BY_102		101
#define AUX_OUT_DIV_BY_103		102
#define AUX_OUT_DIV_BY_104		103
#define AUX_OUT_DIV_BY_105		104
#define AUX_OUT_DIV_BY_106		105
#define AUX_OUT_DIV_BY_107		106
#define AUX_OUT_DIV_BY_108		107
#define AUX_OUT_DIV_BY_109		108
#define AUX_OUT_DIV_BY_110		109
#define AUX_OUT_DIV_BY_111		110
#define AUX_OUT_DIV_BY_112		111
#define AUX_OUT_DIV_BY_113		112
#define AUX_OUT_DIV_BY_114		113
#define AUX_OUT_DIV_BY_115		114
#define AUX_OUT_DIV_BY_116		115
#define AUX_OUT_DIV_BY_117		116
#define AUX_OUT_DIV_BY_118		117
#define AUX_OUT_DIV_BY_119		118
#define AUX_OUT_DIV_BY_120		119
#define AUX_OUT_DIV_BY_121		120
#define AUX_OUT_DIV_BY_122		121
#define AUX_OUT_DIV_BY_123		122
#define AUX_OUT_DIV_BY_124		123
#define AUX_OUT_DIV_BY_125		124
#define AUX_OUT_DIV_BY_126		125
#define AUX_OUT_DIV_BY_127		126
#define AUX_OUT_DIV_BY_128		127


/*******************************************************************************
 * DAC1 Status and Control Register (DAC1STAT)
 ******************************************************************************/

// Enable/Disable Channels
#define ENABLE_LEFT_DAC_CHANNEL     DAC1STATbits.LOEN = 1
#define DISABLE_LEFT_DAC_CHANNEL    DAC1STATbits.LOEN = 0
#define ENABLE_RIGHT_DAC_CHANNEL    DAC1STATbits.ROEN = 1
#define DISABLE_RIGHT_DAC_CHANNEL   DAC1STATbits.ROEN = 0

// Interrupt type
#define DAC_LEFT_INTERRUPT_TYPE     DAC1STATbits.LITYPE
#define DAC_RIGHT_INTERRUPT_TYPE    DAC1STATbits.RITYPE
#define FIFO_EMPTY                  1
#define FIFO_NOT_FULL               0

// Conversion finished
#define DAC_RIGHT_CH_EMPTY          (DAC1STATbits.REMPTY == 1)

/*******************************************************************************
 * DAC1 Default and output data registers
 ******************************************************************************/

#define DAC_DEFAULT_DATA            DAC1DFLT
#define DAC_RIGHT_CH_OUT            DAC1RDAT
#define DAC_LEFT_CH_OUT             DAC1LDAT

/*******************************************************************************
 * DAC Interrupt Flags (IFS4)
 ******************************************************************************/

#define CLEAR_DAC_RIGHT_CH_INTERRUPT_FLAG   IFS4bits.DAC1RIF = 0;
#define SET_DAC_RIGHT_CH_INTERRUPT_FLAG     IFS4bits.DAC1RIF = 1;
#define CLEAR_DAC_LEFT_CH_INTERRUPT_FLAG    IFS4bits.DAC1LIF = 0;
#define SET_DAC_LEFT_CH_INTERRUPT_FLAG      IFS4bits.DAC1LIF = 1;
#define ENABLE_DAC_RIGHT_CH_INTERRUPT       IEC4bits.DAC1RIE = 1;
#define DISABLE_DAC_RIGHT_CH_INTERRUPT      IEC4bits.DAC1RIE = 0;
#define ENABLE_DAC_LEFT_CH_INTERRUPT        IEC4bits.DAC1LIE = 1;
#define DISABLE_DAC_LEFT_CH_INTERRUPT       IEC4bits.DAC1LIE = 0;

/*******************************************************************************
 * DAC Function Prototypes
 ******************************************************************************/

void initDAC(void);

#endif	/* DAC_H */

