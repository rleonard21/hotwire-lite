/*
 * PWM.c
 *
 * Created: 2/23/2022 9:45:24 PM
 *  Author: Robert
 */ 

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "PWM.h"
#include "LED.h"
#include "Power.h"

#define PWM_PERIOD	9999

// EFFECTS: initializes the PWM output
void PWM_init() {
	// set PWM pin to an output
	PWM_PORT.DIRSET = PWM_PIN_bm;
	
	// set the clock divider
	TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV2_gc;
	
	// enable output on the pin and set the timer to single slope PWM
	TCA0.SINGLE.CTRLB = TCA_SINGLE_CMP1_bm | TCA_SINGLE_WGMODE_SINGLESLOPE_gc;
	
	// set the period of the timer
	TCA0.SINGLE.PER = PWM_PERIOD;
	
	// set the duty cycle of the timer
	TCA0.SINGLE.CMP1 = 1024;
	
	// enable the overflow interrupt for triggering the control system
	TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
}

// EFFECTS: starts the PWM output
void PWM_start() {
	TCA0.SINGLE.CTRLB |= TCA_SINGLE_CMP1_bm;
	
	// start the timer
	TCA0.SINGLE.CTRLA |= TCA_SINGLE_ENABLE_bm;
	
// 	LED_on();
}

// EFFECTS: stops the PWM output
void PWM_stop() {
	// stop the timer
	TCA0.SINGLE.CTRLA &= ~TCA_SINGLE_ENABLE_bm;
	
	TCA0.SINGLE.CTRLB &= ~TCA_SINGLE_CMP1_bm;
	
// 	LED_off();
}

// EFFECTS: changes the duty cycle of the PWM
void PWM_update_duty(uint16_t value) {
	TCA0.SINGLE.CMP1 = value;
}

// EFFECTS: updates the duty cycle to a set percentage
void PWM_update_duty_percent(uint8_t percent) {
	uint16_t duty = PWM_PERIOD / 100;
	TCA0.SINGLE.CMP1 = duty * (uint16_t)percent;
}

// EFFECTS: toggles the PWM
void PWM_toggle() {
	TCA0.SINGLE.CTRLA ^= TCA_SINGLE_ENABLE_bm;
}

// EFFECTS: returns 0 if the PWM is currently disabled
uint8_t PWM_is_enabled() {
	return TCA0.SINGLE.CTRLA & TCA_SINGLE_ENABLE_bm;
}

// ISR: executes on the rising edge of the PWM signal
ISR(TCA0_OVF_vect) {
	LED_on();
	uint16_t p = Power_get_power();
	LED_off();
	
	// clear the flag
	TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}

