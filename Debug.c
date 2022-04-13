/*
 * Debug.c
 *
 * Created: 2/28/2022 10:52:47 PM
 *  Author: Robert
 */ 

#include "Debug.h"

void Debug_write_data(uint16_t data) {
	char buf[6];
	utoa(data, buf, 10);
	UART_puts(buf);
	//UART_putc('\n');
}