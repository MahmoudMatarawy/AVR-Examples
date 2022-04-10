/*
 * TIMER.h
 *
 * Created: 4/5/2022 12:43:05 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TIMER_H_
#define TIMER_H_



/*****************************************************************************************/
/*                                   Include headres                                     */
/*****************************************************************************************/
#include <avr/io.h>
#include "TIMER_CONFIG.h"




typedef struct  
{
	uint8_t timer_n;										// For all timers
	uint8_t mode ;											// For all timers
	uint8_t com ;											// For timer 0 and 2
	uint8_t com1a ;											// For timer 1
	uint8_t com1b ;											// For timer 1
	uint32_t clock_select;									// For all timers
	uint8_t compare_match_interrupt_enable;					// For timer 0 and 2
	uint8_t compare_match_A_interrupt_enable;				// For timer 1
	uint8_t compare_match_B_interrupt_enable;				// For timer 1
	uint8_t overflow_interrupt_enable;						// For all timers
	uint8_t input_capture_interrupt_enable;					// For timer 1
	uint8_t ENABLE_TIMER_0_PIN;								// Set 1 to Enable timer 0 pin as output
	uint8_t ENABLE_TIMER_1_A_PIN;							// Set 1 to Enable timer 1 A pin as output
	uint8_t ENABLE_TIMER_1_B_PIN;							// Set 1 to Enable timer 1 B pin as output
	uint8_t ENABLE_TIMER_2_PIN;								// Set 1 to Enable timer 2 pin as output
	}t_init;												// Timers INIT parameters struct.

/* -------------------------------------------------------------------------- */
/*                             Functions Prototype                            */
/* -------------------------------------------------------------------------- */


/***********************************************************************************************/
/*    Function Description    : This function initializes the module						   */
/*    Parameter in            : t_init *param												   */
/*    Return value            : FAILED OR DONE OR FAILED_INIT_BEFORE OR FAILED_NO_CLOCK_SOURCE */ 
/***********************************************************************************************/


unsigned int TIMER_INIT(t_init *param);


#endif /* TIMER_H_ */