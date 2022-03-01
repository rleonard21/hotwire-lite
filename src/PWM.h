/*
 * PWM.h
 *
 * Created: 2/23/2022 9:42:29 PM
 *  Author: Robert
 */ 


#ifndef PWM_H_
#define PWM_H_

#define PWM_PORT	PORTA
#define PWM_PIN_bm	PIN1_bm

// EFFECTS: initializes the PWM output
void PWM_init();

// EFFECTS: starts the PWM output
void PWM_start();

// EFFECTS: stops the PWM output
void PWM_stop();

// EFFECTS: changes the duty cycle of the PWM
void PWM_update_duty(uint16_t value);

// EFFECTS: updates the duty cycle to a set percentage
void PWM_update_duty_percent(uint8_t percent);

// EFFECTS: toggles the PWM
void PWM_toggle();

// EFFECTS: returns 0 if the PWM is currently disabled
uint8_t PWM_is_enabled();

#endif /* PWM_H_ */