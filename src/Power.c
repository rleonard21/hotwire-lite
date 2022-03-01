/*
 * Power.c
 *
 * Created: 2/24/2022 1:46:13 AM
 *  Author: Robert
 */ 

#include "Power.h"
#include <stdint.h>

inline uint16_t Power_get_current() {
	return ADC_single_read(ADC_AMP_CHANNEL);
}

inline uint16_t Power_get_voltage() {
	return ADC_single_read(ADC_VOLT_CHANNEL);
}

uint16_t Power_get_power() {
	return Power_get_voltage() * Power_get_current();
}
