/*
 * hotwire-lite.c
 *
 * Created: 2/22/2022 9:34:55 PM
 * Author : Robert
 */ 

#define F_CPU 20000000

#include "Init.h"
#include "UART.h"
#include "Debug.h"
#include "ADC.h"
#include "Power.h"
#include "Button.h"
#include "PWM.h"
#include "SysTick.h"
#include "LED.h"
#include "Calibrate.h"
#include "PID.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void) {
	
	// initialize peripherals
	Init_clock_setup();
	SysTick_init();
	UART_init(F_CPU);
	
	ADC_init();
 	Button_init();
	PID_init();
	PWM_init();
	
	uint8_t debug_mode = Debounce_read() == 1; // return 1 if the button is currently held low
	debug_mode = 1;
	if(debug_mode) {
		Button_disable();
		UART_enable_tx();
		UART_enable_rx();
	} else {
		LED_init();
	}
	
	sei();
	PWM_start();
	
	// main application
    while (1) {
		// operate hot wire state based on button
// 		if(Button_read()) {
// 			if(PWM_is_enabled())
// 				PWM_stop();
// 			else
// 				PWM_start();
// 		}

		Power_print_measurements();
		
		if(debug_mode)
			Calibrate_update();
	}
		
	return 1;
}

