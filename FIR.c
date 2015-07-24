#include "FIR.h"
#include "dsp.h"    // For fractional definition
#include "DMA.h"    // For NUM_SAMPLES definition

// FIR filter coefficient buffer
fractional coefficients[FILTER_ORDER] __attribute__((space(xmemory), far)) = {
    0.000231, 0.000583, 0.001176, 0.002085, 0.003381, 0.005121, 0.007343,
    0.010059, 0.013243, 0.016833, 0.020727, 0.024788, 0.028851, 0.032730,
    0.036236, 0.039185, 0.041419, 0.042812, 0.043286, 0.042812, 0.041419,
    0.039185, 0.036236, 0.032730, 0.028851, 0.024788, 0.020727, 0.016833,
    0.013243, 0.010059, 0.007343, 0.005121, 0.003381, 0.002085, 0.001176,
    0.000583, 0.000231
};

// FIR filter delay buffer (hold x[n] x[n-1] ... x[n-M+1])
fractional xdelay[FILTER_ORDER] __attribute__((space(ymemory), far));

// Filtered signal output
fractional output_signal[NUM_SAMPLES] __attribute__((space(xmemory), far, 
        aligned(512)));
