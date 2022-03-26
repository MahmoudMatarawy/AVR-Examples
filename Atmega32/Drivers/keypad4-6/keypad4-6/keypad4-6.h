/*
 * keypad4_6.h
 *
 * Created: 3/26/2022 12:14:10 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef KEYPAD46_H_
#define KEYPAD46_H_
#include <stdint.h>
#include "keyconfig.h"
#define ALL_LINES	    (((LINE0_PIN&(1U<<LINE0))>>LINE0)\
&((LINE1_PIN&(1U<<LINE1))>>LINE1)\
&((LINE2_PIN&(1U<<LINE2))>>LINE2)\
&((LINE3_PIN&(1U<<LINE3))>>LINE3)\
&((LINE4_PIN&(1U<<LINE4))>>LINE4)\
&((LINE5_PIN&(1U<<LINE5))>>LINE5))

//functions prototype
void v_Keypad_Init(void);
uint8_t u8_cKeypad_Scan(void);




#endif /* KEYPAD4-6_H_ */