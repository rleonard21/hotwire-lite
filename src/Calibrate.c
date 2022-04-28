/*
 * Calibrate.c
 *
 * Created: 2/25/2022 1:19:13 AM
 *  Author: Robert
 */ 

#include "Calibrate.h"
#include "UART.h"
#include "PWM.h"
#include "PID.h"
#include "LED.h"
#include "Power.h"
#include "EEPROM.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#define CMD_SIZE	3

#define UPDATE_POWER		'P'
#define UPDATE_RESISTOR		'C'

// CMD[0] = command type
// CMD[1] = data high 8
// CMD[2] = data low 8

volatile char calibrate_cmd[CMD_SIZE];
volatile uint8_t cmd_idx = 0;
volatile uint8_t pending_cmd = 0;

// EFFECTS: converts a two digit string like "99" into a number like int(99)
static uint8_t to_char(volatile char *a) {
	return (a[1] - '0') * 10 + a[2] - '0';
}

// EFFECTS: initializes the resistor calibration and power setting after first flash
void Calibrate_init() {
	if(!EEPROM_was_device_calibrated()) {
		EEPROM_save_float(1000.0f, POWER_SETTING_ADDR);
		EEPROM_save_float(3.0f, RESISTOR_CALIBRATION_ADDR);
	}
}

void execute_cmd() {

	if(calibrate_cmd[0] == UPDATE_POWER) {
		UART_puts("ACK\r\n");
		uint8_t power = to_char(calibrate_cmd);
		PID_update_setting(power);
	}
	
	if(calibrate_cmd[0] == UPDATE_RESISTOR) {
		UART_puts("ACK\r\n");
		uint8_t c = to_char(calibrate_cmd);
		Power_calibrate_divider(c);
	}
}

// EFFECTS: handles the UART CLI
void Calibrate_update() {
	if(pending_cmd) {
		execute_cmd();
		pending_cmd = 0;
	}
}

ISR(USART0_RXC_vect) {
	// move the UART char into the packet buffer
	char c = UART_getc();
	
	if(c == '\r' || c == '\n') {
		USART0.STATUS |= USART_RXSIF_bm;
		return;
	}
	
	calibrate_cmd[cmd_idx] = c;
	
	if(++cmd_idx == CMD_SIZE) {
		cmd_idx = 0;
		pending_cmd = 1;
	}

	// clear the interrupt flags
	USART0.STATUS |= USART_RXSIF_bm;
}
