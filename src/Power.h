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

uint16_t Power_get_current();

uint16_t Power_get_voltage();

uint16_t Power_get_power();



#endif /* POWER_H_ */