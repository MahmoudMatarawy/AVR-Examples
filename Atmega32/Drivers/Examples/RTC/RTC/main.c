/*
 * RTC.c
 *
 * Created: 4/11/2022 2:54:19 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "RTC.h"


int main(void)
{
	twi_init();
	RTC_DATE_DATA date ;
	RTC_TIME_DATA time ;
	date.day = 0x03;
	date.mon = 0x10;
	date.yr  = 0x93;
	time.sec = 0x40;
	time.min = 0x25;
	time.hr  = 0x10;
	RTC_SET_TIME(&time);
	RTC_SET_DATE(&date);
    while (1) 
    {
    }
}

