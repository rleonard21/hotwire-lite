//
// Created by robert on 1/30/22.
//

#ifndef HOTWIRE_LITE_V1_0_SKIPPINGAVERAGE_H
#define HOTWIRE_LITE_V1_0_SKIPPINGAVERAGE_H

#include <stdint-gcc.h>

#define SA_BIT_DEPTH        3
#define SA_LENGTH           (1 << SA_BIT_DEPTH)

struct SkippingAverage {
    uint16_t noiseFloor;
    uint16_t accumulator;
    uint16_t data[SA_LENGTH];
    uint16_t *samplePointer;    // points to the oldest data AND where new data is written
};

// EFFECTS: initializes the skipping average filter
void SkippingAverage_init();

// EFFECTS: returns the output of the filter with the given input
uint16_t SkippingAverage_filter_output(uint16_t sample);

// EFFECTS: updates the noise floor of the filter
// NOTE: used during self calibration on boot
void SkippingAverage_calibrate_noise(uint16_t noise_floor);

#endif //HOTWIRE_LITE_V1_0_SKIPPINGAVERAGE_H
