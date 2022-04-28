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

float P_error = 0.0;
float I_error = 0.0;
float D_error = 0.0;
float last_error = 0.0;

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
	float measure = Power_get_power();

	PID_P_error(setting, measure);
	PID_I_error();
	PID_D_error();

	float output = (P_error * P_gain + I_error * I_gain + D_error * D_gain);

	if (output > MAX_PID) output = MAX_PID;
	if (output < MIN_PID) output = MIN_PID;

	PWM_PID_input((int16_t)(output));
}

// EFFECTS: updates the power set point for the PID controller and saves to nonvolatile memory
void PID_update_setting(uint8_t setting_input) {
	setting = (float)(setting_input) * 1000.0f;
	
	EEPROM_save_float(setting, POWER_SETTING_ADDR);
}
