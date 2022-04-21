/*
 * Power.h
 *
 * Created: 2/23/2022 1:06:04 AM
 *  Author: Robert
 */ 


#ifndef POWER_H_
#define POWER_H_

#include "ADC.h"
#include <avr/io.h>

#define ADC_VOLT_CHANNEL	ADC_MUXPOS_AIN2_gc
#define ADC_AMP_CHANNEL		ADC_MUXPOS_AIN3_gc

// EFFECTS: initializes the power measurement
void Power_init();

// returns the measured voltage in mVolts
float Power_get_voltage();

// EFFECTS: returns the measured current in mAmps
float Power_get_current();

// EFFECTS: returns the measured power in mWatts
float Power_get_power();

// EFFECTS: updates the voltage divider multiplier with a calibration value
void Power_calibrate_divider(uint8_t input);

// EFFECTS: prints the most recent measurements
void Power_print_measurements();


#endif /* POWER_H_ */