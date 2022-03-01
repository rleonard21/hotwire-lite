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
