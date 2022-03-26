/*
 * main.c
 *
 * Created: 3/26/2022 12:10:05 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "keypad4-6.h"
#include "lcd4.h"

int main(void)
{
	v_Keypad_Init();
	DDRA = 0xff;
	Lcd4_Init();
	char x =0;
    /* Replace with your application code */
    while (1) 
    {
		x=u8_cKeypad_Scan();
		if (x>0)
		{
			Lcd4_Write_Char(x);
			x=0;
		}
    }
}

