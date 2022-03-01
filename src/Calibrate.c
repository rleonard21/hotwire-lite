/*
 * Calibrate.c
 *
 * Created: 2/25/2022 1:19:13 AM
 *  Author: Robert
 */ 

#include "Calibrate.h"
#include "UART.h"
#include "PWM.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define CMD_SIZE	3

#define UPDATE_PWM_DUTY		'D'

// CMD[0] = command type
// CMD[1] = data high 8
// CMD[2] = data low 8

volatile char calibrate_cmd[CMD_SIZE];
volatile uint8_t cmd_idx = 0;
volatile uint8_t pending_cmd = 0;

volatile char rx_char = '0';

void execute_cmd() {
	if(calibrate_cmd[0] == UPDATE_PWM_DUTY) {
		UART_puts("+ updated duty cycle\n");
		uint8_t duty = (calibrate_cmd[1] - '0') * 10 + calibrate_cmd[2] - '0'; // convert from two-digit ASCII to an integer, 00-99
		PWM_update_duty_percent(duty);
	}
}

void Calibrate_update() {
	if(pending_cmd) {
		execute_cmd();
		pending_cmd = 0;
	}
}

ISR(USART0_RXC_vect) {
	// move the UART char into the packet buffer
	calibrate_cmd[cmd_idx] = UART_getc();
	
	if(cmd_idx++ == CMD_SIZE) {
		cmd_idx = 0;
		pending_cmd = 1;
	}

	// clear the interrupt flags
	USART0.STATUS |= USART_RXSIF_bm;
}