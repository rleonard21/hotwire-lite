/*
 * ADC.c
 *
 * Created: 2/24/2022 1:44:45 AM
 *  Author: Robert
 */ 

#include "ADC.h"
#include <avr/io.h>
#include <stdint.h>

void ADC_init() {
	// set ADC to 10 bit resolution and enable the peripheral
	ADC0.CTRLA |= ADC_RESSEL_10BIT_gc | ADC_ENABLE_bm;
	
	ADC0.CTRLB |= 0x02;
	
	// select VDD as the voltage reference and set ADC_clock=sys_clock/256
	ADC0.CTRLC |= ADC_REFSEL_VDDREF_gc | ADC_PRESC_DIV16_gc;
}

uint16_t ADC_single_read(char channel) {
	// select the ADC channel
	ADC0.MUXPOS  = channel;
	
	// initiate the conversion
	ADC0.COMMAND = ADC_STCONV_bm;
	
	// block until the conversion is ready (can change to interrupt later if necessary)
	while((ADC0.INTFLAGS & ADC_RESRDY_bm) == 0);
	
	// return the result when ready
	return ADC0.RES >> 2;
}