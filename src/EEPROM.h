/*
 * EEPROM.h
 *
 * Created: 4/19/2022 6:12:13 PM
 *  Author: Robert
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#define RESISTOR_CALIBRATION_ADDR	0x00
#define	POWER_SETTING_ADDR			0x10

// EFFECTS: returns true if the EEPROM was updated since first flash. returns false otherwise.
uint8_t EEPROM_was_device_calibrated();
	
// EFFECTS: writes a float to the address in EEPROM
void EEPROM_save_float(float f, uint16_t addr);

// EFFECTS: reads a float from the address in EEPROM
float EEPROM_read_float(uint16_t addr);

#endif /* EEPROM_H_ */