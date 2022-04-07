/*
 * TIMER_CONFIG.h
 *
 * Created: 4/5/2022 12:57:04 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_
#include <stdint.h>

#define TIMER_NUMBERS			 (3U)

//TIMERS
typedef uint8_t TIMER;				// timers enum

#define TIMER_0					((TIMER)0U)
#define TIMER_1					((TIMER)1U)
#define TIMER_2					((TIMER)2U)



// TIMERS PIN
typedef uint8_t TIMER_PINS;

#define TIMER_0_DDR				(DDRB)
#define TIMER_0_PIN				((TIMER_PINS)3U)
#define TIMER_1_A_DDR			(DDRD)
#define TIMER_1_A_PIN			((TIMER_PINS)5U)
#define TIMER_1_B_DDR			(DDRD)
#define TIMER_1_B_PIN			((TIMER_PINS)4U)
#define TIMER_2_DDR				(DDRD)
#define TIMER_2_PIN				((TIMER_PINS)7U)



typedef uint8_t TIMERs_STATUS;

#define NOT_INIT				((TIMERs_STATUS)0U)
#define INIT					((TIMERs_STATUS)1U)
#define FAILED					((TIMERs_STATUS)2U)
#define DONE					((TIMERs_STATUS)3U)
#define FAILED_INIT_BEFORE		((TIMERs_STATUS)4U)



#define ENABLE(x)				(1U<<x)
#define DISABLE(x)				~(1U<<x)



// TIMER MODES
typedef uint8_t TIMER_MODE;

#define NORMAL_MODE				((TIMER_MODE)0U)
#define PWM_PHASE_CORRECT_MODE	((TIMER_MODE)1U)
#define CTC_MODE				((TIMER_MODE)2U)
#define FAST_PWM_MODE			((TIMER_MODE)3U)



// TIMER COMPARE OUTPUT MODE
typedef uint8_t TIMER_OUTPUT_COMPARE_MODE;

#define NORMAL_PORT_MODE		((TIMER_OUTPUT_COMPARE_MODE)0U)
#define TOGGLE_OC_MODE			((TIMER_OUTPUT_COMPARE_MODE)1U)
#define CLEAR_OC_MODE			((TIMER_OUTPUT_COMPARE_MODE)2U)
#define SET_OC_MODE				((TIMER_OUTPUT_COMPARE_MODE)3U)



// CLOCK SELECT MODES
typedef uint32_t CLOCK_SELECT_MODE;

#define NO_CLOCK_SOURCE_MODE	((CLOCK_SELECT_MODE)0U)
#define NO_PRESCALING_MODE		((CLOCK_SELECT_MODE)1U)
#define FALLING_EDGE_MODE		((CLOCK_SELECT_MODE)2U)
#define RISING_EDGE_MODE		((CLOCK_SELECT_MODE)3U)
#define CLK_8_MODE				((CLOCK_SELECT_MODE)8U)
#define CLK_64_MODE				((CLOCK_SELECT_MODE)64U)
#define CLK_256_MODE			((CLOCK_SELECT_MODE)256U)
#define CLK_1024_MODE			((CLOCK_SELECT_MODE)1024U)




// TIMERS REGISTER
#define TIMER_0_COUNTER_REG				(TCNT0)
#define TIMER_0_OUTPUT_COMPARE_REG		(OCR0)
#define TIMER_0_CONTROL_REG				(TCCR0)
#endif /* TIMER_CONFIG_H_ */