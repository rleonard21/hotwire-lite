/*
 * LED.c
 *
 * Created: 2/24/2022 1:09:56 AM
 *  Author: Robert
 */ 

#include "LED.h"

#include <avr/io.h>

void LED_init() {
	PORTA.DIRSET = PIN6_bm;
	PORTA.PIN6CTRL &= ~PORT_PULLUPEN_bm;
}

void LED_on() {
	PORTA.OUTSET = PIN6_bm;
}

void LED_off() {
	PORTA.OUTCLR = PIN6_bm;
}

void LED_toggle() {
	PORTA.IN = PIN6_bm;
}

void LED_input_init() {
	PORTA.DIRCLR = PIN6_bm;
	PORTA.PIN6CTRL |= PORT_PULLUPEN_bm;
}

uint8_t LED_input_is_low() {
	return (PORTA.IN & PIN6_bm) >> PIN6_bp;
}
