/*
 * main.c
 *
 * Created: 3/15/2022 10:22:23 PM
 * Author : Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "lcd4.h"
#include "keypad.h"
#include "calc.h"

int main(void)
{
	DDRB = 0xff;
	DDRA = 0xff;
	Lcd4_Init();
	v_Keypad_Init();
	unsigned char input[100];
	int i_c=0;
	unsigned char x=0;
    /* Replace with your application code */
    while (1) 
    {
		x=u8_cKeypad_Scan();
		if (x=='C')
		{
			clean(input);
			Lcd4_Clear();
		}
		else if (x=='=')
		{
			input[i_c] = x;
			i_c=0;
			Lcd4_Set_Cursor(2,0);
			calculate_res(input);
			//Lcd4_Write_String(input);
		}
		else if(x!=0)
		{
			input[i_c] = x;
			i_c++;
			Lcd4_Write_Char(x);
		}
    }
}

