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
	uint8_t timer_n;
	uint8_t mode ;
	uint8_t com ;
	uint32_t clock_select;
	uint8_t compare_match_interrupt_enable;
	uint8_t overflow_interrupt_enable;
	uint8_t input_capture_interrupt_enable;
	}t_init;

/* -------------------------------------------------------------------------- */
/*                             Functions Prototype                            */
/* -------------------------------------------------------------------------- */


/***********************************************************************************************/
/*    Function Description    : This function initializes the module						   */
/*    Parameter in            : t_init *param												   */
/*    Return value            : FAILED OR DONE OR FAILED_INIT_BEFORE OR FAILED_NO_CLOCK_SOURCE */ 
/***********************************************************************************************/                                                   */


unsigned int timer_init(t_init *param);



#endif /* TIMER_H_ */