//
// Created by Robert Leonard on 2019-07-03.
//
// An implementation of the Ganssle debounce routine.
// http://www.ganssle.com/debouncing-pt2.htm
// https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/
//
// new implementation saves about ~40 bytes of compiled space.

#include "Button.h"
#include <avr/interrupt.h>

volatile uint8_t debounce_num_ticks = 0;
const uint8_t debounce_max_ticks = 40;
volatile uint8_t button_history;
volatile uint8_t button_pressed_flag = 0;

// EFFECTS: starts the debounce service. copies the inputs and enables the overflow interrupt vector.
void Button_init() {
	// button is default set to input
	// enable pull up resistor
	BUTTON_CTRL |= PORT_INVEN_bm | PORT_PULLUPEN_bm;
}

// EFFECTS: reads the current state of the button
static inline uint8_t Debounce_read() {
	return (BUTTON_PORT.IN & BUTTON_PIN_bm) >> BUTTON_PIN_bp;
}

// EFFECTS:  reads the button states and updates the histories of the inputs
//			 to be run by an interrupt periodically
void Debounce_update_service() {
	// button history acts like a shift register, a new reading comes in and the old ones are shifted out left
	button_history <<= 1;
	button_history |= Debounce_read();
	
	if(button_history == BUTTON_IS_PRESSED) button_pressed_flag = 1;
}

// EFFECTS: returns true if the button is in the given state
uint8_t Button_read(uint8_t read_type) {
	if(button_pressed_flag) {
		button_pressed_flag = 0;
		return 1;
	}
	
	return 0;
}
