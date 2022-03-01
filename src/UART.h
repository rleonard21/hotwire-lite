/*
 * UART.h
 *
 * Created: 2/22/2022 11:15:12 PM
 *  Author: Robert
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdint.h>

// EFFECTS: initializes the UART peripheral
void UART_init(unsigned long clk);

// EFFECTS: updates the baud rate of peripheral for clock change
void UART_clock_change(unsigned long clk);

// EFFECTS: sends a character over UART
void UART_putc(char c);

// EFFECTS: sends a string over UART
void UART_puts(char *s);

// EFFECTS: sends num of char of a string over UART
void UART_putsn(volatile char *s, uint8_t num);

// EFFECTS: returns the next char from RX
char UART_getc(void);

// EFFECTS: disables the transmit hardware
void UART_disable_tx(void);

// EFFECTS: enables the transmit hardware
void UART_enable_tx(void);

// EFFECTS: disables the receive hardware
void UART_disable_rx(void);

// EFFECTS: enables the receive hardware
void UART_enable_rx(void);

#endif /* UART_H_ */