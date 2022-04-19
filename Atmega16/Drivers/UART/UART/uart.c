/*
 * uart.c
 *
 * Created: 4/2/2022 6:54:43 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#include "uart.h"

void uart_init(void)
{
	UBRRH  = (baudrate>>8);
	UBRRL  = baudrate ;
	UCSRB |= (1<<TXEN)|(1<<RXEN);
	UCSRC |= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void uart_tx(unsigned char data)
{
	while(!( UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer */
	UDR = data;						/* Put data into buffer, sends the data */
}

unsigned char uart_rx(void)
{
	while (! ((UCSRA) & (1<<RXC)));
	return UDR ;
}
void uart_write_string( char *n )
{
	int x;
	for (x=0;n[x]!='\0';x++)
	{
		uart_tx(n[x]);
	}
}