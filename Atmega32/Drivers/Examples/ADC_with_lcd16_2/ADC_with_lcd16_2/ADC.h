/*
 * ADC.h
 *
 * Created: 4/11/2022 9:19:09 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include "ADC_CONFIG.h"
#include <stdlib.h>
#define F_CPU	8000000UL
#include <util/delay.h>

typedef struct
{
	uint8_t ref_selection;
	uint8_t ADC_LEFT_ADJUST_RESULT_enable;
	uint8_t prescaler_selection;
	uint8_t ADC_Enable_Auto_Trigger;
	uint8_t ADC_Enable_Interrupt;
	uint8_t ADC_Auto_Trigger_Source;
	}ADC_CONFIG;



void ADC_INIT(ADC_CONFIG *param);
uint16_t ADC_READ(uint8_t channel);


#endif /* ADC_H_ */