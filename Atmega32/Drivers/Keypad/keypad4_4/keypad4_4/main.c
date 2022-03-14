/*
 * keypad4_4.c
 *
 * Created: 3/14/2022 2:16:14 AM
 * Author : Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	v_Keypad_Init();
	DDRA = 0xff;
	PORTA = 0;
	int a = 0;
    /* Replace with your application code */
    while (1) 
    {
		PORTA =0;
		//_delay_ms(100);
		a = u8_cKeypad_Scan();
		
		if(a!=0)
		{
			PORTA =a-48;
			_delay_ms(200);
		}
		a=0;
    }
	return 0 ;
}

