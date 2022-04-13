/*
 * LED.h
 *
 * Created: 2/24/2022 1:04:53 AM
 *  Author: Robert
 */ 


#ifndef LED_H_
#define LED_H_

#include <stdint.h>

void LED_init();

void LED_on();

void LED_off();

void LED_toggle();

void LED_input_init();

uint8_t LED_input_is_low();

#endif /* LED_H_ */