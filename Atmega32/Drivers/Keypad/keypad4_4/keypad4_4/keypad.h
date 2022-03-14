#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdint.h>
#include "keypadconfig.h"
#define ALL_LINES	    (((LINE0_PIN&(1U<<LINE0))>>LINE0)\
&((LINE1_PIN&(1U<<LINE1))>>LINE1)\
&((LINE2_PIN&(1U<<LINE2))>>LINE2)\
&((LINE3_PIN&(1U<<LINE3))>>LINE3))

//functions prototype
void v_Keypad_Init(void);
uint8_t u8_cKeypad_Scan(void);





#endif	//KEYPAD_H_