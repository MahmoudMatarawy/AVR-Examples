/*
 * UART.c
 *
 * Created: 4/2/2022 6:24:36 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "uart.h"


int main(void)
{
	uart_init();
	uart_write_string(" Enter .");
	uart_tx(13);
	uart_write_string(" 1 For : Adding user . ");
	uart_tx(13);
	uart_write_string(" 2 For : Deleting user . ");
	uart_tx(13);
	uart_write_string(" 3 For : Opening the gate . ");
	uart_tx(13);
	uart_write_string(" 4 For : Closing the gate . ");
	uart_tx(13);
	uart_write_string(" 5 For : Users information . ");
	uart_tx(13);
	uart_write_string(" 6 For : changing user's password .");
	uart_tx(13);
	uart_write_string(" 7 For : Stopping the Buzzer .");
	uart_tx(13);
	uart_write_string(" 8 For : Setting time and date .");
	uart_tx(13);
	_delay_ms(500);
    while (1) 
    {
		//uart_write('a');
    }
}

