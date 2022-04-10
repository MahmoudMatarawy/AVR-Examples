/*
 * TWI.h
 *
 * Created: 4/4/2022 3:31:22 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TWI_H_
#define TWI_H_
#include <avr/io.h>
#define F_CPU 8000000UL
void twi_init(void);
void twi_start(void);
void twi_stop(void);
void twi_write(uint8_t ui_data);
uint8_t twi_read_ack(void);
uint8_t twi_read_Nack(void);
uint8_t twi_get_status(void);



#endif /* TWI_H_ */