/*
 * TIMER.h
 *
 * Created: 4/5/2022 12:43:05 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#define F_CPU 8000000UL

#include <avr/io.h>
#include "TIMER_CONFIG.h"
#include <util/delay.h>
unsigned int timer_init(int timer_n , char mode , char com , int clock_select);



#endif /* TIMER_H_ */