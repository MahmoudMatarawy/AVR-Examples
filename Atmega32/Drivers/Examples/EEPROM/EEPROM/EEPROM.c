/*
 * EEPROM.c
 *
 * Created: 4/10/2022 11:42:44 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#include "EEPROM.h"


uint8_t EEReadbyte(uint16_t add)
{
	uint8_t data;
	twi_start();
	twi_write(0xA0);		// Device Address
	twi_write(add>>8);		// Address high bits
	twi_write(add);			// Address low bits
	twi_start();			// Restart
	twi_write(0xA1);		// Device Address
	data = twi_read_Nack();
	twi_stop();
	_delay_ms(10);
	return data;
}

void EEWritebyte(uint16_t add , uint8_t data)
{
	twi_start();
	twi_write(0xA0);		// Device Address
	twi_write(add>>8);		// Address high bits
	twi_write(add);			// Address low bits
	twi_write(data);
	twi_stop();
	_delay_ms(1);
}