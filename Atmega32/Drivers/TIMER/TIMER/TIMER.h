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





/*****************************************************************************************/
/*    Function Description    : This function initializes the module                     */
/*    Parameter in            : uint8_t timer_n		(timer number )                      */
/*								timer number : 0 for timer_0 or 1 for timer_1 or		 */
/*											   2 for timer_2							 */
/*								uint8_t mode		(timer mode )						 */
/*								uint8_t com			(output compare match mode)			 */
/*								uint32_t clock_select (operating clock selection or		 */
/*														prescaler )						 */	
/*								uint8_t compare_match_interrupt_enable					 */
/*								uint8_t overflow_interrupt_enable						 */
/*								uint8_t input_capture_interrupt_enable					 */

unsigned int timer_init(t_init *param);



#endif /* TIMER_H_ */