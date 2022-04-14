/*
 * ADC_with_lcd16_2.c
 *
 * Created: 4/13/2022 9:59:04 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "ADC.h"
#include "lcd4.h"
#include <stdlib.h>


int main(void)
{
	DDRC = 0xff;
	Lcd4_Init();
	ADC_CONFIG s1;
	s1.prescaler_selection = 128;
	s1.ref_selection = AVCC ;
	ADC_INIT(&s1);
	int x = 0 ;
	unsigned char y[10];
    /* Replace with your application code */
    while (1) 
    {
		Lcd4_Clear();
		x=ADC_READ(0);
		itoa(x,y,10U);
		Lcd4_Write_String(y);
		_delay_ms(10000);
    }
}

