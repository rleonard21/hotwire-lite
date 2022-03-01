/*
 * Debug.h
 *
 * Created: 2/22/2022 11:23:55 PM
 *  Author: Robert
 */ 


#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdlib.h>
#include <stdint.h>
#include "UART.h"


void Debug_write_data(uint16_t data) {
	char buf[5];
	utoa(data, buf, 10);
	UART_puts(buf);
	UART_putc('\n');
}


#endif /* DEBUG_H_ */