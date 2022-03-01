//
// Created by Robert Leonard on 2019-07-03.
//
// An implementation of the Ganssle debounce routine.
// http://www.ganssle.com/debouncing-pt2.htm
// https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/
//

#ifndef HOTWIRE_CONTROLLER_V1_1_DEBOUNCE_H
#define HOTWIRE_CONTROLLER_V1_1_DEBOUNCE_H

#define BUTTON_PORT		PORTA
#define BUTTON_CTRL		BUTTON_PORT.PIN7CTRL
#define BUTTON_PIN_bm	PIN7_bm
#define BUTTON_PIN_bp	PIN7_bp

#define BUTTON_IS_HIGH		(0b11111111)
#define BUTTON_IS_LOW		(0b00000000)
#define BUTTON_IS_PRESSED	(0b01111111)
#define BUTTON_IS_RELEASED	(0b10000000)

#include <stdint.h>

volatile uint8_t debounce_num_ticks;
const uint8_t debounce_max_ticks;

// EFFECTS: starts the debounce service and initializes the button
void Button_init();

// EFFECTS:  reads the button state and updates the history of the input
void Debounce_update_service();

// EFFECTS: returns true if the button is in the given state
uint8_t Button_read(uint8_t read_type);

#endif //HOTWIRE_CONTROLLER_V1_1_DEBOUNCE_H