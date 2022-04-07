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


/* -------------------------------------------------------------------------- */
/*                             Functions Prototype                            */
/* -------------------------------------------------------------------------- */
unsigned int timer_init(uint8_t timer_n , uint8_t mode , uint8_t com , uint32_t clock_select);



#endif /* TIMER_H_ */