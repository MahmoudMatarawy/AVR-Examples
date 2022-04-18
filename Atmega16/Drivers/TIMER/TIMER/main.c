/*
 * TIMER.c
 *
 * Created: 4/17/2022 11:25:15 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "TIMER.h"
#include <util/delay.h>

int main(void)
{
    t_init t1;
    t1.timer_n = TIMER_0;
    t1.mode = TIMER_0_FAST_PWM_MODE;
    t1.clock_select = CLK_8_MODE ;
    t1.com	 = CLEAR_OC_MODE ;
    t1.ENABLE_TIMER_0_PIN = 1 ;
    TIMER_INIT(&t1);
    t_out t2;
    t2.TIMER_n = 0;
    t2.duty = 50;
    TIMER_SET_DUTY(&t2);
    while (1) 
    {
    }
}

