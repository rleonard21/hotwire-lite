/*
 * hotwire-lite.c
 *
 * Created: 2/22/2022 9:34:55 PM
 * Author : Robert
 */ 

#define FIRMWARE_VERSION "v1.0.0"

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

#define DEBUG_MESSAGE "HOTWIRE LITE; DEBUG ENABLED;\r\nFIRMWARE VERSION "

int main(void) {
	
	// initialize peripherals
	Init_clock_setup();
	SysTick_init();
	UART_init(F_CPU);
	
	Calibrate_init();
	ADC_init();
 	Button_init();
	PID_init();
	PWM_init();
	Power_init();
	
	uint8_t debug_mode = Debounce_read() == 1; // return 1 if the button is currently held low

	if(debug_mode) {
		Button_disable();
		UART_enable_tx();
		UART_enable_rx();
		UART_puts(DEBUG_MESSAGE);
		UART_puts(FIRMWARE_VERSION);
		UART_puts("\r\n");
		_delay_ms(1000);
		PWM_start();
	} else {
		LED_init();
	}
	
	sei();
	
	// main application
    while (1) {
		// operate hot wire state based on button
		if(Button_read() && !debug_mode) {
			if(PWM_is_enabled())
				PWM_stop();
			else
				PWM_start();
		}
		
		if(debug_mode) {
			Calibrate_update();
			Power_print_measurements();
		}
	}
		
	return 1;
}

