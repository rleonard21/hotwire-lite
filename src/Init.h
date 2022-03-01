/*
 * Init.h
 *
 * Created: 2/22/2022 10:48:20 PM
 *  Author: Robert
 */ 


#ifndef INIT_H_
#define INIT_H_

#include <avr/io.h>

#define UNLOCK_CCP() CPU_CCP = CCP_IOREG_gc;

// EFFECTS: Sets the clock to 20MHz with no prescaler
void Init_clock_setup() {
	UNLOCK_CCP();				// unlock protected writes
	CLKCTRL.MCLKCTRLB = 0x00;	// disable the prescaler (also sets prescaler to 2, but disables it)

	UNLOCK_CCP();
	CLKCTRL.MCLKCTRLA = CLKCTRL_CLKSEL_OSC20M_gc;
}



#endif /* INIT_H_ */