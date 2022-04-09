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
typedef uint8_t TIMER;				// TIMERS ENUM

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



typedef uint8_t TIMERs_STATUS;			// STATUS ENUM

#define NOT_INIT				((TIMERs_STATUS)0U)
#define INIT					((TIMERs_STATUS)1U)
#define FAILED					((TIMERs_STATUS)2U)
#define DONE					((TIMERs_STATUS)3U)
#define FAILED_INIT_BEFORE		((TIMERs_STATUS)4U)
#define FAILED_NO_CLOCK_SOURCE	((TIMERs_STATUS)5U)



#define ENABLE(x)				(1U<<x)
#define DISABLE(x)				~(1U<<x)



// TIMER MODES
typedef uint8_t TIMER_0_MODE;			// TIMER 0 MODES ENUM

#define TIMER_0_NORMAL_MODE				((TIMER_0_MODE)0U)
#define TIMER_0_PWM_PHASE_CORRECT_MODE	((TIMER_0_MODE)1U)
#define TIMER_0_CTC_MODE				((TIMER_0_MODE)2U)
#define TIMER_0_FAST_PWM_MODE			((TIMER_0_MODE)3U)


typedef uint8_t TIMER_1_MODE;			// TIMER 1 MODES ENUM

#define TIMER_1_NORMAL_MODE						((TIMER_1_MODE)0U)
#define TIMER_1_PWM_PHASE_CORRECT_8_MODE		((TIMER_1_MODE)1U)
#define TIMER_1_PWM_PHASE_CORRECT_9_MODE		((TIMER_1_MODE)2U)
#define TIMER_1_PWM_PHASE_CORRECT_10_MODE		((TIMER_1_MODE)3U)
#define TIMER_1_CTC_OCR_MODE					((TIMER_1_MODE)4U)
#define TIMER_1_FAST_PWM_8_MODE					((TIMER_1_MODE)5U)
#define TIMER_1_FAST_PWM_9_MODE					((TIMER_1_MODE)6U)
#define TIMER_1_FAST_PWM_10_MODE				((TIMER_1_MODE)7U)
#define TIMER_1_PWM_FREQUENCY_CORRECT_ICR_MODE	((TIMER_1_MODE)8U)
#define TIMER_1_PWM_FREQUENCY_CORRECT_OCR_MODE	((TIMER_1_MODE)9U)
#define TIMER_1_PWM_PHASE_CORRECT_ICR_MODE		((TIMER_1_MODE)10U)
#define TIMER_1_PWM_PHASE_CORRECT_OCR_MODE		((TIMER_1_MODE)11U)
#define TIMER_1_CTC_ICR_MODE					((TIMER_1_MODE)12U)
#define TIMER_1_RESERVED_MODE					((TIMER_1_MODE)13U)		// GENERATE AN ERROR
#define TIMER_1_FAST_PWM_ICR_MODE				((TIMER_1_MODE)14U)
#define TIMER_1_FAST_PWM_OCR_MODE				((TIMER_1_MODE)15U)



typedef uint8_t TIMER_2_MODE;			// TIMER 2 MODES ENUM

#define TIMER_2_NORMAL_MODE				((TIMER_2_MODE)0U)
#define TIMER_2_PWM_PHASE_CORRECT_MODE	((TIMER_2_MODE)1U)
#define TIMER_2_CTC_MODE				((TIMER_2_MODE)2U)
#define TIMER_2_FAST_PWM_MODE			((TIMER_2_MODE)3U)



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
#define CLK_32_MODE				((CLOCK_SELECT_MODE)32U)
#define CLK_64_MODE				((CLOCK_SELECT_MODE)64U)
#define CLK_128_MODE			((CLOCK_SELECT_MODE)128U)
#define CLK_256_MODE			((CLOCK_SELECT_MODE)256U)
#define CLK_1024_MODE			((CLOCK_SELECT_MODE)1024U)




// TIMERS REGISTER
#define TIMER_INTERRUPT_MASK_REG		(TIMSK)
#define TIMER_INTERRUPT_FLAG_REG		(TIFR)


#define TIMER_0_COUNTER_REG				(TCNT0)
#define TIMER_0_OUTPUT_COMPARE_REG		(OCR0)
#define TIMER_0_CONTROL_REG				(TCCR0)



#define TIMER_1_COUNTER_REG				(TCNT1)
#define TIMER_1_COUNTER_H_REG			(TCNT1H)
#define TIMER_1_COUNTER_L_REG			(TCNT1L)
#define TIMER_1_OUTPUT_COMPARE_A_REG	(OCR1A)
#define TIMER_1_OUTPUT_COMPARE_B_REG	(OCR1B)
#define TIMER_1_CONTROL_A_REG			(TCCR1A)
#define TIMER_1_CONTROL_B_REG			(TCCR1B)
#define TIMER_1_INPUT_CAPTURE_REG		(ICR1)
#define TIMER_1_INPUT_CAPTURE_H_REG		(ICR1H)
#define TIMER_1_INPUT_CAPTURE_L_REG		(ICR1L)




#define TIMER_2_COUNTER_REG				(TCNT2)
#define TIMER_2_OUTPUT_COMPARE_REG		(OCR2)
#define TIMER_2_CONTROL_REG				(TCCR2)




// TIMER_0_CONTROL_REG_BITS
#define TIMER_0_FORCE_OUTPUT_COMPARE			(FOC0)
#define TIMER_0_WAVEFORME_GENERATOR_MODE_BIT_0	(WGM00)
#define TIMER_0_WAVEFORME_GENERATOR_MODE_BIT_1	(WGM01)
#define TIMER_0_COMPARE_MATCH_BIT_0				(COM00)
#define TIMER_0_COMPARE_MATCH_BIT_1				(COM01)
#define TIMER_0_CLOCK_SELECT_BIT_0				(CS00)
#define TIMER_0_CLOCK_SELECT_BIT_1				(CS01)
#define TIMER_0_CLOCK_SELECT_BIT_2				(CS02)

// TIMER 0 INTERRUPT MASK REG BITS
#define TIMER_0_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE	(OCIE0)
#define TIMER_0_OVERFLOW_INTERRUPT_ENABLE				(TOIE0)

// TIMER 0 INTERRUPT FLAG REG BITS
#define TIMER_0_OUTPUT_COMPARE_FLAG				(OCF0)
#define TIMER_0_OVERFLOW_FLAG					(TOV0)



// TIMER_1_CONTROL_REG_A_BITS
#define TIMER_1_FORCE_OUTPUT_COMPARE_A			(FOC1A)
#define TIMER_1_FORCE_OUTPUT_COMPARE_B			(FOC1B)
#define TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_0	(WGM10)
#define TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_1	(WGM11)
#define TIMER_1_COMPARE_MATCH_BIT_A_0			(COM1A0)
#define TIMER_1_COMPARE_MATCH_BIT_A_1			(COM1A1)
#define TIMER_1_COMPARE_MATCH_BIT_B_0			(COM1B0)
#define TIMER_1_COMPARE_MATCH_BIT_B_1			(COM1B1)



// TIMER_1_CONTROL_REG_B_BITS
#define TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_2	(WGM12)
#define TIMER_1_WAVEFORME_GENERATOR_MODE_BIT_3	(WGM13)
#define TIMER_1_INPUT_CAPTURE_NOISE_CANCELER	(ICNC1)
#define TIMER_1_INPUT_CAPTURE_EDGE_SELECT		(ICES1)
#define TIMER_1_CLOCK_SELECT_BIT_0				(CS10)
#define TIMER_1_CLOCK_SELECT_BIT_1				(CS11)
#define TIMER_1_CLOCK_SELECT_BIT_2				(CS12)


// TIMER 1 INTERRUPT MASK REG BITS
#define TIMER_1_INPUT_CAPTURE_INTERRUPT_ENABLE			(TICIE1)
#define TIMER_1_OUTPUT_COMPARE_A_MATCH_INTERRUPT_ENABLE	(OCIE1A)
#define TIMER_1_OUTPUT_COMPARE_B_MATCH_INTERRUPT_ENABLE	(OCIE1B)
#define TIMER_1_OVERFLOW_INTERRUPT_ENABLE				(TOIE1)



// TIMER 1 INTERRUPT FLAG REG BITS
#define TIMER_1_INPUT_CAPTURE_FLAG						(ICF1)
#define TIMER_1_OUTPUT_COMPARE_A_FLAG					(OCF1A)
#define TIMER_1_OUTPUT_COMPARE_B_FLAG					(OCF1B)
#define TIMER_1_OVERFLOW_FLAGE							(TOV1)



// TIMER_2_CONTROL_REG_BITS
#define TIMER_2_FORCE_OUTPUT_COMPARE			(FOC2)
#define TIMER_2_WAVEFORME_GENERATOR_MODE_BIT_0	(WGM20)
#define TIMER_2_WAVEFORME_GENERATOR_MODE_BIT_1	(WGM21)
#define TIMER_2_COMPARE_MATCH_BIT_0				(COM20)
#define TIMER_2_COMPARE_MATCH_BIT_1				(COM21)
#define TIMER_2_CLOCK_SELECT_BIT_0				(CS20)
#define TIMER_2_CLOCK_SELECT_BIT_1				(CS21)
#define TIMER_2_CLOCK_SELECT_BIT_2				(CS22)



// TIMER 2 INTERRUPT MASK REG BITS
#define TIMER_2_OUTPUT_COMPARE_MATCH_INTERRUPT_ENABLE	(OCIE2)
#define TIMER_2_OVERFLOW_INTERRUPT_ENABLE				(TOIE2)


// TIMER 2 INTERRUPT FLAG REG BITS
#define TIMER_2_OUTPUT_COMPARE_FLAG				(OCF2)
#define TIMER_2_OVERFLOW_FLAG					(TOV2)




typedef uint8_t ENABLE_INTERRUPT;

#define ENABLE_OUTPUT_COMPARE_MATCH_INTERRUPT	((ENABLE_INTERRUPT)1U)
#define ENABLE_OVERFLOW_INTERRUPT				((ENABLE_INTERRUPT)2U)
#define ENABLE_INPUT_CAPTURE_INTERRUPT			((ENABLE_INTERRUPT)3U)
#define ENABLE_OUTPUT_COMPARE_A_MATCH_INTERRUPT	((ENABLE_INTERRUPT)4U)
#define ENABLE_OUTPUT_COMPARE_B_MATCH_INTERRUPT	((ENABLE_INTERRUPT)5U)


#endif /* TIMER_CONFIG_H_ */