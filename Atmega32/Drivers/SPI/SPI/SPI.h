/*
 * SPI.h
 *
 * Created: 4/3/2022 7:21:05 PM
 *  Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

#define SPI_DDR						DDRB
#define MISO						6
#define MOSI						5
#define SCK							7
#define SS							4
#define SPI_INTERRUPT_FLAG			SPIF
#define SPI_DATA_REG				SPDR
#define SPI_CONTROL_REG				SPCR
#define SPI_STATUS_REG				SPSR
#define SPI_ENABLE_BIT				SPE
#define SPI_MASTER_SELECT_BIT		MSTR
#define SPI_PRESCALER_FIRST_BIT		SPR0
#define SPI_PRESCALER_SEC_BIT		SPR1
#define SPI_DOUBLE_SPEED			SPI2X


void spi_master_init(void);
void spi_slave_init(void);
void spi_tx(unsigned char data);
unsigned char spi_rx(void);



#endif /* SPI_H_ */