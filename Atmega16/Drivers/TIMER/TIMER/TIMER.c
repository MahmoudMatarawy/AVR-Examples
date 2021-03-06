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
uint8_t TIMER_PRESCALER[TIMER_NUMBERS];
uint8_t TIMER_PIN_STATUS[TIMER_NUMBERS+1];

unsigned int TIMER_INIT(t_init *param)
{
	if (TIMER_STATUS[param->timer_n] == NOT_INIT)
	{
		switch(param->timer_n)
		{
			// Timer 0 INIT.
			case TIMER_0 :
			switch(param->mode)
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
			switch(param->com)
			{
				case TOGGLE_OC_MODE : 
				if ((param->mode == TIMER_0_PWM_PHASE_CORRECT_MODE )||(param->mode == TIMER_0_FAST_PWM_MODE))
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
			switch(param->clock_select)
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
			if(param->compare_match_interrupt_enable == ENABLE_OUTPUT_COMPARE_MATCH_INTERRUPT )
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_0_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE); 
			}
			
			if(param->overflow_interrupt_enable == ENABLE_OVERFLOW_INTERRUPT)
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_0_OVERFLOW_INTERRUPT_ENABLE);
			}
			
			if (param->ENABLE_TIMER_0_PIN == INIT)
			{
				TIMER_0_DDR |= ENABLE(TIMER_0_PIN);
			}
			TIMER_STATUS[param->timer_n] = INIT;
			TIMER_PRESCALER[param->timer_n] = param->clock_select;
			TIMER_PIN_STATUS[param->timer_n] = INIT;
			return DONE ;
			break;
			
			
			// Timer 1
			case TIMER_1 :
			switch(param->mode)
			{
				case TIMER_1_PWM_PHASE_CORRECT_8_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0);
				break;
				
				case TIMER_1_PWM_PHASE_CORRECT_9_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				break;
				
				case TIMER_1_PWM_PHASE_CORRECT_10_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				break;
				
				case TIMER_1_CTC_OCR_MODE:
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2);
				break;
				
				case TIMER_1_FAST_PWM_8_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2);
				break;
				
				case TIMER_1_FAST_PWM_9_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2);
				break;
				
				case TIMER_1_FAST_PWM_10_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2);
				break;
				
				case TIMER_1_PWM_FREQUENCY_CORRECT_ICR_MODE:
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_PWM_FREQUENCY_CORRECT_OCR_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_PWM_PHASE_CORRECT_ICR_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_PWM_PHASE_CORRECT_OCR_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_CTC_ICR_MODE:
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_RESERVED_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_FAST_PWM_ICR_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
				
				case TIMER_1_FAST_PWM_OCR_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1);
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2) | ENABLE(TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3);
				break;
			}
			
			switch(param->com1a)
			{
				case TOGGLE_OC_OCR1A_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_COMPARE_MATCH_BIT_A_0);
				break;
				
				case CLEAR_OC_OCR1A_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_COMPARE_MATCH_BIT_A_1);
				break;
				
				case SET_OC_OCR1A_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_COMPARE_MATCH_BIT_A_0) | ENABLE(TIMER_1_COMPARE_MATCH_BIT_A_1);
				break;
			}
			
			switch(param->com1b)
			{
				case TOGGLE_OC_OCR1B_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_COMPARE_MATCH_BIT_B_0);
				break;
				
				case CLEAR_OC_OCR1B_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_COMPARE_MATCH_BIT_B_1);
				break;
				
				case SET_OC_OCR1B_MODE:
				TIMER_1_CONTROL_A_REG |= ENABLE(TIMER_1_COMPARE_MATCH_BIT_B_0) | ENABLE(TIMER_1_COMPARE_MATCH_BIT_B_1);
				break;
			}
			
			switch(param->clock_select)
			{
				case NO_CLOCK_SOURCE_MODE : 
				return FAILED_NO_CLOCK_SOURCE;
				break;
				
				case NO_PRESCALING_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_0);
				break;
				
				case CLK_8_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_1);
				break;
				
				case CLK_64_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_0_CLOCK_SELECT_BIT_1);
				break;
				
				case CLK_256_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_2);
				break;
				
				case CLK_1024_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_1_CLOCK_SELECT_BIT_2);
				break;
				
				case FALLING_EDGE_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_1) | ENABLE(TIMER_1_CLOCK_SELECT_BIT_2);
				break;
				
				case RISING_EDGE_MODE :
				TIMER_1_CONTROL_B_REG |= ENABLE(TIMER_1_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_1_CLOCK_SELECT_BIT_1) | ENABLE(TIMER_1_CLOCK_SELECT_BIT_2);
				break;
			}
			
			if(param->compare_match_A_interrupt_enable == ENABLE_OUTPUT_COMPARE_A_MATCH_INTERRUPT )
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_1_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE);
			}
			
			if(param->compare_match_B_interrupt_enable == ENABLE_OUTPUT_COMPARE_B_MATCH_INTERRUPT )
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_1_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE);
			}
			
			if(param->input_capture_interrupt_enable == ENABLE_INPUT_CAPTURE_INTERRUPT )
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_1_INPUT_CAPTURE_INTERRUPT_ENABLE);
			}
			
			if(param->overflow_interrupt_enable == ENABLE_OVERFLOW_INTERRUPT)
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_1_OVERFLOW_INTERRUPT_ENABLE);
			}
			
			if (param->ENABLE_TIMER_1_A_PIN == INIT)
			{
				TIMER_1_A_DDR |= ENABLE(TIMER_1_A_PIN);
				TIMER_PIN_STATUS[param->timer_n] = INIT;
			}
			
			if (param->ENABLE_TIMER_1_B_PIN == INIT)
			{
				TIMER_1_B_DDR |= ENABLE(TIMER_1_B_PIN);
				TIMER_PIN_STATUS[(param->timer_n)+2] = INIT;
			}
			TIMER_STATUS[param->timer_n] = INIT;
			TIMER_PRESCALER[param->timer_n] = param->clock_select;
			return DONE ;
			break;
			
			
			// TIIMER 2
			case TIMER_2:
			switch(param->mode)
			{
				case TIMER_2_PWM_PHASE_CORRECT_MODE:
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_WAVEFORME_GENERATOR_MODE_BIT_0);
				break;
				
				case TIMER_2_CTC_MODE:
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_WAVEFORME_GENERATOR_MODE_BIT_1);
				break;
				
				case TIMER_2_FAST_PWM_MODE:
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_WAVEFORME_GENERATOR_MODE_BIT_0) | ENABLE(TIMER_2_WAVEFORME_GENERATOR_MODE_BIT_1);
				break;
			}
			
			switch(param->com)
			{
				case TOGGLE_OC_MODE :
				if ((param->mode == TIMER_2_PWM_PHASE_CORRECT_MODE )||(param->mode == TIMER_2_FAST_PWM_MODE))
				{
					return FAILED;
				}
				else{
					TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_COMPARE_MATCH_BIT_0);
				}
				break;
				
				case CLEAR_OC_MODE :
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_COMPARE_MATCH_BIT_1);
				break;
				
				case  SET_OC_MODE :
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_COMPARE_MATCH_BIT_0) | ENABLE(TIMER_2_COMPARE_MATCH_BIT_1);
				break;
			}
			
			switch(param->clock_select)
			{
				case NO_CLOCK_SOURCE_MODE :
				return FAILED_NO_CLOCK_SOURCE ;
				break;
				
				case NO_PRESCALING_MODE :
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_0);
				break;
				
				case CLK_8_MODE :
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_1);
				break;
				
				case CLK_32_MODE:
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_2_CLOCK_SELECT_BIT_1);
				break;
				
				case CLK_64_MODE:
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_2);
				break;
				
				case CLK_128_MODE:
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_2_CLOCK_SELECT_BIT_2);
				break;
				
				case CLK_256_MODE :
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_1) | ENABLE(TIMER_2_CLOCK_SELECT_BIT_2);
				break;
				
				case CLK_1024_MODE :
				TIMER_2_CONTROL_REG |= ENABLE(TIMER_2_CLOCK_SELECT_BIT_0) | ENABLE(TIMER_2_CLOCK_SELECT_BIT_1) | ENABLE(TIMER_2_CLOCK_SELECT_BIT_2);
				break;
			}
			if(param->compare_match_interrupt_enable == ENABLE_OUTPUT_COMPARE_MATCH_INTERRUPT )
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_0_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE);
			}
			
			if(param->overflow_interrupt_enable == ENABLE_OVERFLOW_INTERRUPT)
			{
				TIMER_INTERRUPT_MASK_REG |= ENABLE(TIMER_0_OVERFLOW_INTERRUPT_ENABLE);
			}
			if (param->ENABLE_TIMER_2_PIN == INIT)
			{
				TIMER_2_DDR |= ENABLE(TIMER_2_PIN);
			}
			TIMER_STATUS[param->timer_n] = INIT;
			TIMER_PRESCALER[param->timer_n] = param->clock_select;
			TIMER_PIN_STATUS[param->timer_n] = INIT;
			return DONE ;
			break;
		}
	}
	else{
		return FAILED_INIT_BEFORE;
	}
	return TIMER_STATUS[param->timer_n];
}


uint8_t TIMER_SET(uint8_t TIMER_n,unsigned int data)
{
	if (TIMER_STATUS[TIMER_n] == INIT)
	{
		switch(TIMER_n)
		{
			case TIMER_0 :
			TIMER_0_COUNTER_REG = data;
			break;
			
			case TIMER_1 :
			TIMER_1_COUNTER_REG = data;
			break;
			
			case TIMER_2 :
			TIMER_2_COUNTER_REG = data;
			break;
		}
	}
	else{
		return FAILED;
	}
	return DONE;
}

t_status TIMER_READ(uint8_t TIMER_n)
{
	t_status st;
	if (TIMER_STATUS[TIMER_n] == INIT)
	{
		switch(TIMER_n)
		{
			case TIMER_0 :
			st.data = TIMER_0_COUNTER_REG;
			break;
			
			case TIMER_1 :
			st.data = TIMER_1_COUNTER_REG;
			break;
			
			case TIMER_2 :
			st.data = TIMER_2_COUNTER_REG;
			break;
		}
		st.status = DONE ;
	}
	else{
		st.status = FAILED;
	}
	return st ;
}


uint8_t TIMER_SET_DUTY(t_out *param)
{
	if (TIMER_STATUS[param->TIMER_n] == INIT)
	{
		if (TIMER_PIN_STATUS[(param->TIMER_n)+(param->TIMER_PIN)] == INIT)
		{
			switch(param->TIMER_n)
			{
				case TIMER_0 :
				TIMER_0_OUTPUT_COMPARE_REG =  ((((param->duty)*255))/100)+1;
				break;
				
				case TIMER_1 :
				switch(param->TIMER_PIN)
				{
					case 0 :
					TIMER_1_OUTPUT_COMPARE_A_REG = ((((param->duty)*255))/100)+1;
					break;
					
					case 1 :
					TIMER_1_OUTPUT_COMPARE_B_REG = ((((param->duty)*255))/100)+1;
					break;
				}
				break;
				
				case TIMER_2 :
				TIMER_2_OUTPUT_COMPARE_REG = ((((param->duty)*255)+1)/100);
				break;
			}
		}
		else{
			return FAILED;
		}
	}
	else{
		return FAILED;
	}
	return DONE;
}