#ifndef		KEYPADCONFIG_H_
#define		KEYPADCONFIG_H_

#include <avr/io.h>

#define		ROW0			0
#define		ROW0_DDR		DDRC
#define		ROW0_PORT		PORTC

#define		ROW1			1
#define		ROW1_DDR		DDRC
#define		ROW1_PORT		PORTC

#define		ROW2			2
#define		ROW2_DDR		DDRC
#define		ROW2_PORT		PORTC

#define		ROW3			3
#define		ROW3_DDR		DDRC
#define		ROW3_PORT		PORTC

#define		LINE0			4
#define		LINE0_DDR		DDRC
#define		LINE0_PIN		PINC
#define		LINE0_PULLUP	PORTC


#define		LINE1			5
#define		LINE1_DDR		 DDRC
#define		LINE1_PIN		 PINC
#define		LINE1_PULLUP	PORTC

#define		LINE2			6
#define		LINE2_DDR		DDRC
#define		LINE2_PIN		PINC
#define		LINE2_PULLUP	PORTC

#define		LINE3			7
#define		LINE3_DDR		DDRC
#define		LINE3_PIN		PINC
#define		LINE3_PULLUP	PORTC




#endif		//KEYPADCONFIG_H_