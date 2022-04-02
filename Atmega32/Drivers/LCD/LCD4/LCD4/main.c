/*
 * LCD4.c
 *
 * Created: 3/13/2022 2:54:54 AM
 * Author : Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com 
 */ 


#include "lcd4.h"

int main(void)
{
	DDRA = 0xff;
	Lcd4_Init();
    while (1) 
    {
		Lcd4_Set_Cursor(1,1);
		Lcd4_Write_String(((unsigned char*)"Mahmoud"));
		_delay_ms(200);
		Lcd4_Set_Cursor(2,1);
		Lcd4_Write_String(((unsigned char*)"Sarhan"));
		 _delay_ms(200);
		 Lcd4_Clear();
    }
}

