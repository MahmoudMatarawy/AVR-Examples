/*
 * main.c
 *
 * Created: 3/13/2022 5:43:17 PM
 * Author : Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "lcd8.h"

int main(void)
{
	DDRA = 0xff;
	DDRB = 0xff;
	Lcd8_Init();
    /* Replace with your application code */
    while (1) 
    {
		Lcd8_Set_Cursor(1,1);
		Lcd8_Write_String("Mahmoud");
		Lcd8_Set_Cursor(2,1);
		Lcd8_Write_String("Sarhan");
		_delay_ms(200);
		Lcd8_Clear();
		_delay_ms(50);
    }
}

