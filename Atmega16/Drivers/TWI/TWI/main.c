/*
 * TWI.c
 *
 * Created: 4/17/2022 2:56:22 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#include "TWI.h"


int main(void)
{
	twi_init();
	twi_start();
	twi_write(0xaf);
	twi_stop();
    /* Replace with your application code */
    while (1) 
    {
    }
}

