/*
 * EEPROM.h
 *
 * Created: 4/10/2022 11:43:29 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>
#include "TWI.h"
#include <util/delay.h>

void EEWritebyte(uint16_t add , uint8_t data);
uint8_t EEReadbyte(uint16_t add);


#endif /* EEPROM_H_ */