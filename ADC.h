/*
 * ADC.h
 *
 * Created: 2/22/2022 11:44:26 PM
 *  Author: Robert
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void ADC_init();

uint16_t ADC_single_read(char channel);

#endif /* ADC_H_ */