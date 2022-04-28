// PID.h
// Created by Robert Leonard on 10/27/19.
//

#ifndef HOTWIRE_CONTROLLER_V1_1_PID_H
#define HOTWIRE_CONTROLLER_V1_1_PID_H

#include <stdint.h>

volatile int pid_num_ticks;
volatile int pid_max_ticks;

// EFFECTS: initializes the PID controller
void PID_init();

// EFFECTS: updates the PID loop
void PID_update_service();

// EFFECTS: updates the power set point for the PID controller and saves to nonvolatile memory
void PID_update_setting(uint8_t setting_input);

#endif //HOTWIRE_CONTROLLER_V1_1_PID_H