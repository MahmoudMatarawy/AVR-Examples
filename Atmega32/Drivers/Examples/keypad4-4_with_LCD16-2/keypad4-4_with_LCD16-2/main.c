/*
 * main.c
 *
 * Created: 3/15/2022 9:45:34 PM
 * Author : Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "lcd4.h"
#include "keypad.h"

int main(void)
{
	DDRA = 0xff;
	Lcd4_Init();
	v_Keypad_Init();
	int a = 0;
    /* Replace with your application code */
    while (1) 
    {
		a = u8_cKeypad_Scan();
		if(a!=0)
		{
			if(a=='C')
			{
				Lcd4_Clear();
			}
			else{
				Lcd4_Write_Char(a);
			}
			
		}
		
    }
}

