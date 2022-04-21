/*
 * PID.c
 *
 * Created: 2/28/2022 10:44:21 PM
 *  Author: Robert
 */ 
// PID.c
// Created by Robert Leonard on 10/27/19.
//

#include <avr/eeprom.h>

#include "PID.h"
#include "Debug.h"
#include "PWM.h"
#include "Power.h"
#include "UART.h"
#include "EEPROM.h"

#define MAX_PID    (100)
#define MIN_PID    (-100)
#define MAX_GAIN    (99.9)

float P_error = 0.0;
float I_error = 0.0;
float D_error = 0.0;
float last_error = 0.0;
volatile uint8_t PID_enabled = 0;

float P_gain = 0.20;
float I_gain = 0.05;
float D_gain = 0.00;

// setting in mWatts
volatile float setting = 5000.0f;

static void PID_init_setting() {
	setting = EEPROM_read_float(POWER_SETTING_ADDR);
}

// EFFECTS: initializes the PID controller
void PID_init() {
	PID_enabled = 1;
	PID_init_setting();
}

void PID_P_error(float set, float measure) {
	P_error = set - measure;
}

void PID_I_error() {
	I_error += P_error;

	if (I_error > 50) I_error = 50;     // restrict the output of the I term
	if (I_error < -50) I_error = -50; // "integral windup"
}

void PID_D_error() {
	D_error = P_error - last_error; // TODO: should be measured not error derivative
	last_error = P_error;
}

// EFFECTS: updates the PID loop
void PID_update_service() {
	if(!PID_enabled) return;

	float measure = Power_get_power();

	PID_P_error(setting, measure);
	PID_I_error();
	PID_D_error();

	float output = (P_error * P_gain + I_error * I_gain + D_error * D_gain);

	if (output > MAX_PID) output = MAX_PID;
	if (output < MIN_PID) output = MIN_PID;

	PWM_PID_input((int16_t)(output));
}

// EFFECTS: returns the current P gain
float PID_get_p() {
	return P_gain;
}

// EFFECTS: returns the current I gain
float PID_get_i() {
	return I_gain;
}

// EFFECTS: returns the current D gain
float PID_get_d() {
	return D_gain;
}

void add_helper(float *gain, float value) {
	if (*gain + value >= MAX_GAIN) {
		*gain = MAX_GAIN;
	} else if (*gain + value <= 0.0) {
		*gain = 0.0;
	} else {
		*gain += value;
	}
}

// EFFECTS: adds value to P gain
void PID_add_p(float value) {
	add_helper(&P_gain, value);
}

// EFFECTS: adds value to I gain
void PID_add_i(float value) {
	add_helper(&I_gain, value);
}

// EFFECTS: adds value to D gain
void PID_add_d(float value) {
	add_helper(&D_gain, value);
}

// EFFECTS: saves gains to EEPROM
void PID_save_gains() {

}

// EFFECTS: stops the PID controller
void PID_disable() {
	//PID_enabled = 0;
}

// EFFECTS: starts the PID controller
void PID_enable() {
	PID_enabled = 1;
}

void PID_update_setting(uint8_t setting_input) {
	setting = (float)(setting_input) * 1000.0f;
	
	EEPROM_save_float(setting, POWER_SETTING_ADDR);
}
