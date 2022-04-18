/*
 * SPI.c
 *
 * Created: 4/17/2022 11:29:46 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include "SPI.h"
#include <util/delay.h>

int main(void)
{
	spi_master_init();
	_delay_ms(2000);
    while (1) 
    {
		spi_tx(0xf8);
		_delay_ms(2000);
    }
}

