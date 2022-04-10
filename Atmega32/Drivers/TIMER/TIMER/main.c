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
	t_init t1;
	t1.timer_n = TIMER_0;
	t1.mode = TIMER_0_FAST_PWM_MODE;
	t1.clock_select = CLK_8_MODE ;
	t1.com	 = CLEAR_OC_MODE ;
	TIMER_INIT(&t1);
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

