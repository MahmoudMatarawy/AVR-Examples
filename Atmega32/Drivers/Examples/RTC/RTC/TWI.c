/*
 * TWI.c
 *
 * Created: 4/4/2022 3:30:56 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#include "TWI.h"


// Function to initialize TWI 
void twi_init(void)
{
	// set SCL to 100KHZ
	TWSR = 0X00;
	TWBR = 32;
	//enable TWI 
	TWCR = (1<<TWEN);
}

// function to start TWI
void twi_start(void)
{
	// SET TWI to start mode 
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	// WAIT till TWI start 
	while ((TWCR & (1<<TWINT))==0);
}

// function to stop TWI
void twi_stop(void)
{
	// SET TWI to stop mode 
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

// function to write 
void twi_write(uint8_t u8_data)
{
	TWDR = u8_data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT))==0);
}

// function to read in ACK mode
uint8_t twi_read_ack(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT))==0);
	return TWDR;
}

// function to read in NACK mode 
uint8_t twi_read_Nack(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT))==0);
	return TWDR;
}

// function to get the status of TWI 
uint8_t twi_get_status(void)
{
	uint8_t status ;
	status = TWSR & 0xf8;
	return status;
}