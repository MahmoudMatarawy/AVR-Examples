/*
 * main.c
 *
 * Created: 4/3/2022 7:19:45 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#define F_CPU 8000000UL 
#include "SPI.h"
#include <util/delay.h>
int main(void)
{
    /* Replace with your application code */
	spi_master_init();
	_delay_ms(2000);
    while (1) 
    {
		spi_tx('a');
		_delay_ms(2000);
    }
}

