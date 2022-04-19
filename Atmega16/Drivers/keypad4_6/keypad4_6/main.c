/*
 * keypad4_6.c
 *
 * Created: 4/19/2022 7:30:36 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "keypad4-6.h"


int main(void)
{
    v_Keypad_Init();
    DDRA = 0xff;
    char x =0;
    while (1)
    {
	    x=u8_cKeypad_Scan();
	    if (x>0)
	    {
		    PORTA = x-48;
		    x=0;
	    }
    }
}

