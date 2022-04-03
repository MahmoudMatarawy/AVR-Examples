/*
 * uart.h
 *
 * Created: 4/2/2022 6:54:59 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef UART_H_
#define UART_H_


#include <avr/io.h>



#define  F_CPU 12000000UL

#include <util/delay.h>


#define  baud 9600
#define  baudrate ((F_CPU)/(baud*16UL)-1)
void uart_init(void);
void uart_tx(unsigned char data);
unsigned char uart_rx(void);
void uart_write_string( char *n );

#endif /* UART_H_ */