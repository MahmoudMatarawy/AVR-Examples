/*
 * SPI.c
 *
 * Created: 4/3/2022 7:20:41 PM
 *  Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "SPI.h"

void spi_master_init(void)
{
	// set MOSI , SCK and SS as output
	SPI_DDR = (1<<MOSI) | (1<<SCK) | (1<<SS) ;
	// set MISO as input
	SPI_DDR &= ~(1<<MISO);
	// enable SPI and select master mode with a prescaler f/16
	SPI_CONTROL_REG = (1<<SPI_ENABLE_BIT)|(1<<SPI_MASTER_SELECT_BIT)|(1<<SPI_PRESCALER_FIRST_BIT);
}


void spi_slave_init(void)
{
	// set MISO as output
	SPI_DDR |= (1<<MISO);
	// set MOSI , SCK and SS as input
	SPI_DDR &=~(1<<MOSI)& ~(1<<SCK) & ~(1<<SS);
	// enable SPI
	SPI_CONTROL_REG = (1 << SPI_ENABLE_BIT );
}

void spi_tx(unsigned char data)
{
	SPDR = data ;				// Write data into the buffer
	while (!(SPSR & (1<<SPIF) ));	//Wait until transmit complete
}

unsigned char spi_rx(void)
{
	while(!(SPI_STATUS_REG & (1<<SPI_INTERRUPT_FLAG)));	//Wait until RX complete
	return SPI_DATA_REG;
}