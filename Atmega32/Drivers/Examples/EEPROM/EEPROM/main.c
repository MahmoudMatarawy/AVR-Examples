/*
 * EEPROM.c
 *
 * Created: 4/10/2022 11:41:01 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "EEPROM.h"

int main(void)
{
	twi_init();
	DDRA = 0xff;
	_delay_ms(10);
	EEWritebyte(0x20,0xFA);
	_delay_ms(5000);
	PORTA = EEReadbyte(0x20);
	_delay_ms(10000);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

