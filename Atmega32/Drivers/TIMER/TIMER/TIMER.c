/*
 * TIMER.c
 *
 * Created: 4/5/2022 12:42:48 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "TIMER.h"

// TIMER 0 STATUS
uint8_t TIMER_STATUS[TIMER_NUMBERS];

unsigned int timer_init(uint8_t timer_n , uint8_t mode , uint8_t com , uint32_t clock_select)
{
	if (TIMER_STATUS[timer_n] == NOT_INIT)
	{
		switch(timer_n)
		{
			// Timer 0 INIT.
			case TIMER_0 :
			switch(mode)
			{
				case TIMER_0_PWM_PHASE_CORRECT_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_WAVEFORME_GENERATOR_MODE_BIT_0);
				break;
				
				case TIMER_0_CTC_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_WAVEFORME_GENERATOR_MODE_BIT_1);
				break;
				
				case TIMER_0_FAST_PWM_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_WAVEFORME_GENERATOR_MODE_BIT_0)|ENABLE(TIMER_0_WAVEFORME_GENERATOR_MODE_BIT_1);
				break;
			}
			switch(com)
			{
				case TOGGLE_OC_MODE : 
				if ((mode == TIMER_0_PWM_PHASE_CORRECT_MODE )||(mode == TIMER_0_FAST_PWM_MODE))
				{
					return FAILED;
				}
				else{
					TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_COMPARE_MATCH_BIT_0);
				}
				break;
				
				case CLEAR_OC_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_COMPARE_MATCH_BIT_1);
				break;
				
				case  SET_OC_MODE : 
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_COMPARE_MATCH_BIT_0) | ENABLE(TIMER_0_COMPARE_MATCH_BIT_1);
				break;
			}
			switch(clock_select)
			{
				case NO_CLOCK_SOURCE_MODE : 
				return FAILED_NO_CLOCK_SOURCE ;
				break;
				
				case NO_PRESCALING_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_0);
				break;
				
				case CLK_8_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_1);
				break;
				
				case CLK_64_MODE:
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_0_CLOCK_SELECT_BIT_1);
				break;
				
				case CLK_256_MODE:
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_2);
				break;
				
				case CLK_1024_MODE:
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_0_CLOCK_SELECT_BIT_2);
				break;
				
				case FALLING_EDGE_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_1) | ENABLE(TIMER_0_CLOCK_SELECT_BIT_2);
				break;
				
				case RISING_EDGE_MODE :
				TIMER_0_CONTROL_REG |= ENABLE(TIMER_0_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_0_CLOCK_SELECT_BIT_1) | ENABLE(TIMER_0_CLOCK_SELECT_BIT_2);
				break;
			}
			TIMER_STATUS[timer_n] = INIT;
			return DONE ;
		}
	}
	else{
		return FAILED_INIT_BEFORE;
	}
	return TIMER_STATUS[timer_n];
}