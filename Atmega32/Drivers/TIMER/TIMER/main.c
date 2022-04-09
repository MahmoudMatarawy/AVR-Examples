/*
 * main.c
 *
 * Created: 4/5/2022 12:42:25 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#define F_CPU 8000000UL
#include "TIMER.h"
#include <util/delay.h>

int main(void)
{
	DDRC = 0xff;
	timer_init(0,TIMER_0_FAST_PWM_MODE,CLEAR_OC_MODE,CLK_8_MODE);
	//TCNT0 =0;
    while (1) 
    {
		for(int i = 0 ; i<255 ; i++)
		{
			TIMER_0_OUTPUT_COMPARE_REG = i ;
			_delay_ms(20);
		}
		_delay_ms(10000);
    }
}

