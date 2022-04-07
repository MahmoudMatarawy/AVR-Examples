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
			TIMER_0_DDR |= ENABLE(TIMER_0_PIN);
			switch(mode)
			{
				case PWM_PHASE_CORRECT_MODE :
				switch(com)
				{
					case TOGGLE_OC_MODE :
					return FAILED ;
					break;
					
					case CLEAR_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM01);  break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					case  SET_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00)| ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(COM00) | ENABLE(COM01); break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					default:
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM00);
						break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
				}
				break;
				
				case CTC_MODE :
				switch(com)
				{
					case TOGGLE_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					case CLEAR_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					case  SET_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(COM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					default:
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM01); break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
				}
				break;
				
				case FAST_PWM_MODE :
				switch(com)
				{
					case TOGGLE_OC_MODE :
					return FAILED ;
					break;
					
					case CLEAR_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;			
										
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS02);
						break;				
											
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					case  SET_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(COM00) | ENABLE(COM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					default:
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS00);
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS01);
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS02);
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS00) | ENABLE(CS02);
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02);
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(WGM00) | ENABLE(WGM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
				}
				break;
				
				default:
				switch(com)
				{
					case TOGGLE_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS00) ;
						break;
						
						case CLK_8_MODE : 
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS01) ;
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS02) ;
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS00) | ENABLE(CS02) ;
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(COM00) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					case CLEAR_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS00) ;
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS01) ;
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS02) ;
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02) ;
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(COM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					case  SET_OC_MODE :
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) ;
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01) ;
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS02) ;
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS02) ;
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) | ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						default:
						TIMER_0_CONTROL_REG |= ENABLE(COM00) | ENABLE(COM01) ; break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
					
					default:
					switch(clock_select)
					{
						case NO_PRESCALING_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS00) ;
						break;
						
						case CLK_8_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS01) ;
						break;
						
						case CLK_64_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS00) | ENABLE(CS01);
						break;
						
						case CLK_256_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS02) ;
						break;
						
						case CLK_1024_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS00) | ENABLE(CS02) ;
						break;
						
						case FALLING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						case RISING_EDGE_MODE :
						TIMER_0_CONTROL_REG |= ENABLE(CS00) | ENABLE(CS01) | ENABLE(CS02) ;
						break;
						
						default:
						return FAILED;
						break;
					}
					TIMER_STATUS[timer_n] = INIT;
					return DONE ;
					break;
				}
				break;
			}
		}
	}
	else {
		return FAILED_INIT_BEFORE ;
	}
	return DONE ;
}