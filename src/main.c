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

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>




int main(void) {
	
	// initialize peripherals
	Init_clock_setup();
	SysTick_init();
	UART_init(F_CPU);
	LED_init();
	ADC_init();
// 	Button_init();
	PWM_init();
	sei();
	
	// enable UART
	UART_enable_tx();
	UART_enable_rx();
	PWM_start(); 
	
    while (1) {
// 		if(Button_read(BUTTON_IS_PRESSED)) {
// 			if(PWM_is_enabled())
// 				PWM_stop();
// 			else
// 				PWM_start();
// 		}
		
 		Calibrate_update();

	}
}

