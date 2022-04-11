/*
 * RTC.c
 *
 * Created: 4/11/2022 2:56:13 AM
 *  Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#include "RTC.h"

void RTC_SET_TIME(RTC_TIME_DATA *param)
{
	twi_start();
	twi_write(0xD0);		// Device address for writing
	twi_write(0);			// set register pointer to 0
	twi_write(param->sec);
	twi_write(param->min);
	twi_write(param->hr);
	twi_stop();
}

void RTC_SET_DATE(RTC_DATE_DATA *param)
{
	twi_start();
	twi_write(0xD0);		// Device address for writing
	twi_write(0x04);		// set register pointer to 4
	twi_write(param->day);
	twi_write(param->mon);
	twi_write(param->yr);
	twi_stop();
}
RTC_TIME_DATA RTC_GET_TIME(void)
{
	RTC_TIME_DATA s1;
	twi_start();
	twi_write(0xD0);		// Device address for writing
	twi_write(0);			// set register pointer to 0
	twi_start();			// restart
	twi_write(0xD1);		// Device address for reading
	s1.sec = twi_read_ack();
	s1.min = twi_read_ack();
	s1.hr  = twi_read_Nack();
	twi_stop();
	return s1;
}

RTC_DATE_DATA RTC_GET_DATE(void)
{
	RTC_DATE_DATA s1 ;
	twi_start();
	twi_write(0xD0);		// Device address for writing
	twi_write(4);			// set register pointer to 4
	twi_start();			// restart
	twi_write(0xD1);		// Device address for reading
	s1.day = twi_read_ack();
	s1.mon = twi_read_ack();
	s1.yr  = twi_read_Nack();
	twi_stop();
	return s1;
}