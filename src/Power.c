/*
 * Power.c
 *
 * Created: 2/24/2022 1:46:13 AM
 *  Author: Robert
 */ 

#include "Power.h"
#include "UART.h"
#include "Debug.h"
#include "PWM.h"
#include <stdint.h>

static const float adc_scalar = 4.8828f; // vcc / 2^10 * 1000 = 5/1024 * 1000
static float voltage_divider_multiplier = 3.0f; // divider = true_vcc / measured_vcc ; calibrates for resistor tolerance

static float previous_voltage = 0.0f;
static float previous_current = 0.0f;
static float previous_power = 0.0f;

static uint8_t data_ready = 0;

// EFFECTS: returns the ADC reading for the current
static inline uint16_t Power_get_current_raw() {
	return ADC_single_read(ADC_AMP_CHANNEL);
}

// EFFECTS: returns the ADC reading for the input voltage
static inline uint16_t Power_get_voltage_raw() {
	return ADC_single_read(ADC_VOLT_CHANNEL);
}

// returns the measured voltage in mVolts
float Power_get_voltage() {
	return (float)(Power_get_voltage_raw()) * adc_scalar * voltage_divider_multiplier;
}

// EFFECTS: returns the measured current in mAmps
float Power_get_current() {
	return (float)(Power_get_current_raw()) * adc_scalar * PWM_get_duty_cycle();
}

// EFFECTS: returns the measured power in mWatts
float Power_get_power() {
	float i = Power_get_current();
	float v = Power_get_voltage();
	
	float power = v * i / 1000.0;
	
	previous_voltage = v;
	previous_current = i;
	previous_power = power;
	
	data_ready = 1;
	
	return power;
}

// EFFECTS: updates the voltage divider multiplier with a calibration value
void Power_calibrate_divider(uint8_t input) {
	float c = (float)(input) / 100.0f; // example: 17 -> 0.17
	voltage_divider_multiplier = 2.50f + c;
}

// EFFECTS: prints the most recent measurements
void Power_print_measurements() {
	// only prints data when new measurements have been taken, i.e. @1kHz
	// prevents using UART in the interrupt, also prevents using UART while measuring to prevent crosstalk
	if(data_ready) {
		uint16_t duty_cycle = (uint16_t)(PWM_get_duty_cycle() * 1000.0f);
		
		Debug_write_data(previous_voltage);
		UART_putc(',');
		Debug_write_data(previous_current);
		UART_putc(',');
		Debug_write_data(previous_power);
		UART_putc(',');
		Debug_write_data(duty_cycle);
		UART_puts("\r\n");
		
		data_ready = 0;
	}
}
