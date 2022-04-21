/*
 * SysTick.c
 *
 * Created: 2/23/2022 11:03:41 PM
 *  Author: Robert
 */ 

#include "SysTick.h"
#include "Button.h"
#include "Calibrate.h"

#include <avr/io.h>
#include <avr/interrupt.h>

// EFFECTS: initialized the system tick interrupt
void SysTick_init() {
	// timer TCB0 is already initialized to periodic interrupt mode with no pre scaler.
	
	// set systick period (set the TOP value to the capture/compare register)
	// systick frequency = (20MHz/2/CCMP) = 10MHz / 100 = 100KHz (0.01ms period)
	TCB0.CCMP = 1000; 
	
	// enable the timer with half clock frequency (10MHz)
	TCB0.CTRLA |= TCB_CLKSEL_CLKDIV2_gc | TCB_ENABLE_bm;
	
	// enable the interrupt
	TCB0.INTCTRL = TCB_CAPT_bm;
}

ISR(TCB0_INT_vect) {
	
	// Debounce service
	if(debounce_num_ticks++ > debounce_max_ticks) {
		Debounce_update_service();
		debounce_num_ticks = 0;
	}

	TCB0.INTFLAGS = TCB_CAPT_bm;
}