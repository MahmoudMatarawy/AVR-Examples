/*
 * main.c
 *
 * Created: 4/4/2022 3:17:23 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 



#include "TWI.h"
#include <util/delay.h>
int main(void)
{
	twi_init();
	int i = 0 ;
	
    /* Replace with your application code */
    while (1) 
    {
		twi_start();
		twi_write(i);
		_delay_ms(2000);
		twi_stop();
		_delay_ms(50);
		i++;
    }
}

