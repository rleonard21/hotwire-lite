/*
 * Calibrate.h
 *
 * Created: 2/25/2022 1:18:59 AM
 *  Author: Robert
 */ 


#ifndef CALIBRATE_H_
#define CALIBRATE_H_

#include <stdint.h>

// EFFECTS: initializes the resistor calibration and power setting after first flash
void Calibrate_init();

// EFFECTS: handles the UART CLI
void Calibrate_update();

#endif /* CALIBRATE_H_ */