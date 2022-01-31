//
// Created by robert on 1/30/22.
//

#include "SkippingAverage.h"

struct SkippingAverage SAFilter;

// EFFECTS: increments the buffer pointer or resets to beginning if overrun
uint16_t *SA_increment_pointer(uint16_t *ptr) {
    if(++ptr == SAFilter.data + SA_LENGTH)
        return SAFilter.data;
    else
        return ptr;
}

// EFFECTS: adds a new sample to the buffer and overwrites and returns oldest sample
uint16_t SA_LIFO_update(uint16_t sample) {
    uint16_t victim = *SAFilter.samplePointer;
    *SAFilter.samplePointer = sample;
    SAFilter.samplePointer = SA_increment_pointer(SAFilter.samplePointer);

    return victim;
}

// EFFECTS: initializes the skipping average filter
void SkippingAverage_init() {
    SAFilter.noiseFloor = 0;
    SAFilter.samplePointer = SAFilter.data;
}

// EFFECTS: returns the output of the filter with the given input
uint16_t SkippingAverage_filter_output(uint16_t sample) {
    // skip samples that are near zero and within the noise floor
    if(sample <= SAFilter.noiseFloor)
        return SAFilter.accumulator >> SA_BIT_DEPTH;

    // pop the oldest sample and add the new sample
    uint16_t victim = SA_LIFO_update(sample);

    // update the accumulator
    SAFilter.accumulator += sample;
    SAFilter.accumulator -= victim;

    // return the average
    return SAFilter.accumulator >> SA_BIT_DEPTH;
}

// EFFECTS: updates the noise floor of the filter
// NOTE: used during self calibration on boot
void SkippingAverage_calibrate_noise(uint16_t noise_floor) {
    SAFilter.noiseFloor = noise_floor;
}
