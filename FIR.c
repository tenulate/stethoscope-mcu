#include "FIR.h"
#include "dsp.h"    // For fractional definition
#include "DMA.h"    // For NUM_SAMPLES definition

// FIR filter coefficient buffer
fractional coefficients[FILTER_ORDER] __attribute__((space(xmemory), far)) = {
    0x0007, 0x0013, 0x0026, 0x0044, 0x006e, 0x00a7, 0x00f0, 0x0149, 0x01b1,
    0x0227, 0x02a7, 0x032c, 0x03b1, 0x0430, 0x04a3, 0x0504, 0x054d, 0x057a,
    0x058a, 0x057a, 0x054d, 0x0504, 0x04a3, 0x0430, 0x03b1, 0x032c, 0x02a7,
    0x0227, 0x01b1, 0x0149, 0x00f0, 0x00a7, 0x006e, 0x0044, 0x0026, 0x0013,
    0x0007
};

// FIR filter delay buffer (hold x[n] x[n-1] ... x[n-M+1])
fractional xdelay[FILTER_ORDER] __attribute__((space(ymemory), far));

// Filtered signal output
fractional output_signal[NUM_SAMPLES] __attribute__((space(xmemory), far, 
        aligned(512)));
