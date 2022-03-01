/*
 * UART.c
 *
 * Created: 2/22/2022 11:15:52 PM
 *  Author: Robert
 */ 

#include "UART.h"
#include <avr/io.h>

#define UROUND(x) ((2UL*(x)+1)/2)
#define BAUD_RATE		9600

#define UART_TX_PORT	PORTA
#define UART_TX_bm		PIN6_bm
#define UART_RX_PORT	PORTA
#define UART_RX_bm		PIN7_bm


// EFFECTS: initializes the UART peripheral
void UART_init(unsigned long clk) {
	// configure baud generator
	UART_clock_change(clk);

	// enable RX interrupt
	USART0.CTRLA |= USART_RXCIE_bm;
}


// EFFECTS: updates the baud rate of peripheral for clock change
inline void UART_clock_change(unsigned long clk) {
	// formula from data sheet section 24.3.2.1.1
	USART0.BAUD = UROUND(4UL * clk / BAUD_RATE);
}


// EFFECTS: sends a character over UART
void UART_putc(char c) {
	// wait until transmit buffer is empty
	while((USART0.STATUS & USART_DREIF_bm) == 0);

	// put new character into transmit buffer
	USART0.TXDATAL = c;
}


// EFFECTS: sends a string over UART
void UART_puts(char *s) {
	// transmit each character of the string
	for(char *ptr = s; *ptr != '\0'; ptr++) {
		UART_putc(*ptr);
	}
}


// EFFECTS: helper function for determining if a character is ready from RX buffer
static uint8_t data_ready(void) {
	return (USART0.STATUS & USART_RXCIF_bm) != 0;
}


// EFFECTS: returns the next char from RX
inline char UART_getc(void) {
	//while(!data_ready());
	return USART0_RXDATAL;
}


// EFFECTS: disables the transmit hardware
void UART_disable_tx(void) {
	// set the transmit pin to high impedance
	UART_TX_PORT.OUTCLR = UART_TX_bm;
	UART_TX_PORT.DIRCLR = UART_TX_bm;

	// disable the transmit hardware
	USART0.CTRLB &= ~USART_TXEN_bm;
}


// EFFECTS: enables the transmit hardware
void UART_enable_tx(void) {
	// set transmit pin to asserted output
	UART_TX_PORT.OUTSET = UART_TX_bm;
	UART_TX_PORT.DIRSET = UART_TX_bm;

	// enable the transmit hardware
	USART0.CTRLB |= USART_TXEN_bm;
}


// EFFECTS: disables the receive hardware
void UART_disable_rx(void) {
	// disable receive hardware
	USART0.CTRLB &= ~USART_RXEN_bm;
}


// EFFECTS: enables the receive hardware
void UART_enable_rx(void) {
	// enable receive hardware
	USART0.CTRLB |= USART_RXEN_bm;
}