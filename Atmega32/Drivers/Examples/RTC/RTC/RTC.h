/*
 * RTC.h
 *
 * Created: 4/11/2022 2:56:26 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef RTC_H_
#define RTC_H_
#include <avr/io.h>
#include <stdint.h>
#include "TWI.h"

typedef struct
{
	uint8_t sec ;
	uint8_t min ; 
	uint8_t hr	;
	} RTC_TIME_DATA;

typedef struct
{
	uint8_t day ;
	uint8_t mon ;
	uint16_t yr	;
	}RTC_DATE_DATA;

void RTC_SET_TIME(RTC_TIME_DATA *param);
void RTC_SET_DATE(RTC_DATE_DATA *param);
RTC_TIME_DATA RTC_GET_TIME(void);
RTC_DATE_DATA RTC_GET_DATE(void);

#endif /* RTC_H_ */