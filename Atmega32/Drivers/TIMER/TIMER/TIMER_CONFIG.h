/*
 * TIMER_CONFIG.h
 *
 * Created: 4/5/2022 12:57:04 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define TIMER_NUMBERS			 3

//TIMERS
#define TIMER_0					 0
#define TIMER_1					 1
#define TIMER_2					 2

// TIMER 0 PIN
#define TIMER_0_DDR				DDRB
#define TIMER_0_PIN				 3


#define FAILED_INIT_BEFORE		 2
#define FAILED					 0
#define DONE					 1
#define NOT_INIT				 0
#define INIT					 1
#define ENABLE(x)				(1<<x)
#define DISABLE(x)				~(1<<x)

// TIMER MODES
#define NORMAL_MODE				'N'
#define PWM_PHASE_CORRECT_MODE	'P'
#define CTC_MODE				'C'
#define FAST_PWM_MODE			'F'

// TIMER COMPARE OUTPUT MODE
#define NORMAL_PORT_MODE		'N'
#define TOGGLE_OC_MODE			'T'
#define CLEAR_OC_MODE			'C'
#define SET_OC_MODE				'S'

// CLOCK SELECT MODES
#define NO_CLOCK_SOURCE_MODE	0
#define NO_PRESCALING_MODE		1
#define CLK_8_MODE				8
#define CLK_64_MODE				64
#define CLK_265_MODE			265
#define CLK_1024_MODE			1024
#define FALLING_EDGE_MODE		2
#define RISING_EDGE_MODE		3

#define TIMER_0_COUNTER_REG				TCNT0
#define TIMER_0_OUTPUT_COMPARE_REG		OCR0
#define TIMER_0_CONTROL_REG				TCCR0
#endif /* TIMER_CONFIG_H_ */