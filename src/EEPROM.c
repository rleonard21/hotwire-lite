/*
 * EEPROM.c
 *
 * Created: 4/19/2022 6:12:02 PM
 *  Author: Robert
 */ 

#include <avr/eeprom.h>

#include "EEPROM.h"

float EEMEM eeprom_base;
uint8_t EEMEM eeprom_set_base;

int set_addr = 0x50;

// EFFECTS: returns true if the EEPROM was updated since first flash. returns false otherwise.
uint8_t EEPROM_was_device_calibrated() {
	uint8_t set = eeprom_read_byte(&eeprom_set_base + set_addr);
	
	if(set != 0xAA) {
		eeprom_update_byte(&eeprom_set_base + set_addr, 0xAA);
		
		return 0;
	}
	
	return 1;
}


// EFFECTS: writes a float to the address in EEPROM
void EEPROM_save_float(float f, uint16_t addr) {
	eeprom_update_float(&eeprom_base + addr, f);
}

// EFFECTS: reads a float from the address in EEPROM
float EEPROM_read_float(uint16_t addr) {
	return eeprom_read_float(&eeprom_base + addr);
}