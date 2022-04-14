/*
 * lcd4.c
 *
 * Created: 3/13/2022 2:56:43 AM
 *  Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#include "lcd4.h"



#define eS_PORTA0 0
#define eS_PORTA1 1
#define eS_PORTA2 2
#define eS_PORTA3 3
#define eS_PORTA4 4
#define eS_PORTA5 5
#define eS_PORTA6 6
#define eS_PORTA7 7
#define eS_PORTB0 10
#define eS_PORTB1 11
#define eS_PORTB2 12
#define eS_PORTB3 13
#define eS_PORTB4 14
#define eS_PORTB5 15
#define eS_PORTB6 16
#define eS_PORTB7 17
#define eS_PORTC0 20
#define eS_PORTC1 21
#define eS_PORTC2 22
#define eS_PORTC3 23
#define eS_PORTC4 24
#define eS_PORTC5 25
#define eS_PORTC6 26
#define eS_PORTC7 27
#define eS_PORTD0 30
#define eS_PORTD1 31
#define eS_PORTD2 32
#define eS_PORTD3 33
#define eS_PORTD4 34
#define eS_PORTD5 35
#define eS_PORTD6 36
#define eS_PORTD7 37

#ifndef D0
#define D0 eS_PORTA0
#define D1 eS_PORTA1
#define D2 eS_PORTA2
#define D3 eS_PORTA3
#endif
#define D4 eS_PORTC0
#define D5 eS_PORTC1
#define D6 eS_PORTC2
#define D7 eS_PORTC3
#define RS eS_PORTC4
#define EN eS_PORTC6


/*
*Function name : pinChange
*Parameters	   : int
*return		   : VOID
*purpose       : CHANGING PIN CONDITION
*
*/
void pinChange(int a, int b)
{
	if(b == 0)
	{
		if(a == eS_PORTA0)
		PORTA &= ~(1<<PA0);
		else if(a == eS_PORTA1)
		PORTA &= ~(1<<PA1);
		else if(a == eS_PORTA2)
		PORTA &= ~(1<<PA2);
		else if(a == eS_PORTA3)
		PORTA &= ~(1<<PA3);
		else if(a == eS_PORTA4)
		PORTA &= ~(1<<PA4);
		else if(a == eS_PORTA5)
		PORTA &= ~(1<<PA5);
		else if(a == eS_PORTA6)
		PORTA &= ~(1<<PA6);
		else if(a == eS_PORTA7)
		PORTA &= ~(1<<PA7);
		else if(a == eS_PORTB0)
		PORTB &= ~(1<<PB0);
		else if(a == eS_PORTB1)
		PORTB &= ~(1<<PB1);
		else if(a == eS_PORTB2)
		PORTB &= ~(1<<PB2);
		else if(a == eS_PORTB3)
		PORTB &= ~(1<<PB3);
		else if(a == eS_PORTB4)
		PORTB &= ~(1<<PB4);
		else if(a == eS_PORTB5)
		PORTB &= ~(1<<PB5);
		else if(a == eS_PORTB6)
		PORTB &= ~(1<<PB6);
		else if(a == eS_PORTB7)
		PORTB &= ~(1<<PB7);
		else if(a == eS_PORTC0)
		PORTC &= ~(1<<PC0);
		else if(a == eS_PORTC1)
		PORTC &= ~(1<<PC1);
		else if(a == eS_PORTC2)
		PORTC &= ~(1<<PC2);
		else if(a == eS_PORTC3)
		PORTC &= ~(1<<PC3);
		else if(a == eS_PORTC4)
		PORTC &= ~(1<<PC4);
		else if(a == eS_PORTC5)
		PORTC &= ~(1<<PC5);
		else if(a == eS_PORTC6)
		PORTC &= ~(1<<PC6);
		else if(a == eS_PORTC7)
		PORTC &= ~(1<<PC7);
		else if(a == eS_PORTD0)
		PORTD &= ~(1<<PD0);
		else if(a == eS_PORTD1)
		PORTD &= ~(1<<PD1);
		else if(a == eS_PORTD2)
		PORTD &= ~(1<<PD2);
		else if(a == eS_PORTD3)
		PORTD &= ~(1<<PD3);
		else if(a == eS_PORTD4)
		PORTD &= ~(1<<PD4);
		else if(a == eS_PORTD5)
		PORTD &= ~(1<<PD5);
		else if(a == eS_PORTD6)
		PORTD &= ~(1<<PD6);
		else if(a == eS_PORTD7)
		PORTD &= ~(1<<PD7);
	}
	else
	{
		if(a == eS_PORTA0)
		PORTA |= (1<<PA0);
		else if(a == eS_PORTA1)
		PORTA |= (1<<PA1);
		else if(a == eS_PORTA2)
		PORTA |= (1<<PA2);
		else if(a == eS_PORTA3)
		PORTA |= (1<<PA3);
		else if(a == eS_PORTA4)
		PORTA |= (1<<PA4);
		else if(a == eS_PORTA5)
		PORTA |= (1<<PA5);
		else if(a == eS_PORTA6)
		PORTA |= (1<<PA6);
		else if(a == eS_PORTA7)
		PORTA |= (1<<PA7);
		else if(a == eS_PORTB0)
		PORTB |= (1<<PB0);
		else if(a == eS_PORTB1)
		PORTB |= (1<<PB1);
		else if(a == eS_PORTB2)
		PORTB |= (1<<PB2);
		else if(a == eS_PORTB3)
		PORTB |= (1<<PB3);
		else if(a == eS_PORTB4)
		PORTB |= (1<<PB4);
		else if(a == eS_PORTB5)
		PORTB |= (1<<PB5);
		else if(a == eS_PORTB6)
		PORTB |= (1<<PB6);
		else if(a == eS_PORTB7)
		PORTB |= (1<<PB7);
		else if(a == eS_PORTC0)
		PORTC |= (1<<PC0);
		else if(a == eS_PORTC1)
		PORTC |= (1<<PC1);
		else if(a == eS_PORTC2)
		PORTC |= (1<<PC2);
		else if(a == eS_PORTC3)
		PORTC |= (1<<PC3);
		else if(a == eS_PORTC4)
		PORTC |= (1<<PC4);
		else if(a == eS_PORTC5)
		PORTC |= (1<<PC5);
		else if(a == eS_PORTC6)
		PORTC |= (1<<PC6);
		else if(a == eS_PORTC7)
		PORTC |= (1<<PC7);
		else if(a == eS_PORTD0)
		PORTD |= (1<<PD0);
		else if(a == eS_PORTD1)
		PORTD |= (1<<PD1);
		else if(a == eS_PORTD2)
		PORTD |= (1<<PD2);
		else if(a == eS_PORTD3)
		PORTD |= (1<<PD3);
		else if(a == eS_PORTD4)
		PORTD |= (1<<PD4);
		else if(a == eS_PORTD5)
		PORTD |= (1<<PD5);
		else if(a == eS_PORTD6)
		PORTD |= (1<<PD6);
		else if(a == eS_PORTD7)
		PORTD |= (1<<PD7);
	}
}

/*
*Function name : LCD4_PORT
*Parameters	   : unsigned int
*return		   : VOID
*purpose       : CHANGING PIN CONDITION
*
*/
void Lcd4_Port(unsigned int UN_CH_LCD_VAR1)
{
	if(UN_CH_LCD_VAR1 & 1)
	pinChange(D4,1);
	else
	pinChange(D4,0);
	
	if(UN_CH_LCD_VAR1 & 2)
	pinChange(D5,1);
	else
	pinChange(D5,0);
	
	if(UN_CH_LCD_VAR1 & 4)
	pinChange(D6,1);
	else
	pinChange(D6,0);
	
	if(UN_CH_LCD_VAR1 & 8)
	pinChange(D7,1);
	else
	pinChange(D7,0);
}

/*
*Function name : Lcd_Cmd
*Parameters	   : CHAR
*return		   : void
*purpose       : sets the RS=0 , EN =1 , EN=0
*
*/
void Lcd4_Cmd(unsigned int UN_CH_LCD_VAR1)
{
	pinChange(RS,0);             // => RS = 0
	Lcd4_Port(UN_CH_LCD_VAR1);
	pinChange(EN,1);            // => E = 1
	_delay_ms(1);
	pinChange(EN,0);             // => E = 0
	_delay_ms(1);
}

/*
*Function name : Lcd4_Clear
*Parameters	   : NONE
*return		   : void
*purpose       : CLEARS LCD
*
*/
void Lcd4_Clear()
{
	Lcd4_Cmd(0);
	Lcd4_Cmd(1);
}

/*
*Function name : Lcd4_Set_Cursor
*Parameters	   : unsigned int
*return		   : void
*purpose       : Sets the cursor position
*
*/
void Lcd4_Set_Cursor(unsigned int UN_CH_LCD_ROW, unsigned int UN_CH_LCD_COLUMN)
{
	unsigned int UN_CH_LCD_VAR2 = 0 ,UN_CH_LCD_VAR3 = 0 ,UN_CH_LCD_VAR4 = 0 ;
	if(UN_CH_LCD_ROW == 1)
	{
		UN_CH_LCD_VAR2 = 0x80 + UN_CH_LCD_COLUMN;
		UN_CH_LCD_VAR3 = UN_CH_LCD_VAR2>>4;
		UN_CH_LCD_VAR4 = (0x80+UN_CH_LCD_COLUMN) & 0x0F;
		Lcd4_Cmd(UN_CH_LCD_VAR3);
		Lcd4_Cmd(UN_CH_LCD_VAR4);
	}
	else if(UN_CH_LCD_ROW == 2)
	{
		UN_CH_LCD_VAR2 = 0xC0 + UN_CH_LCD_COLUMN;
		UN_CH_LCD_VAR3 = UN_CH_LCD_VAR2>>4;
		UN_CH_LCD_VAR4 = (0xC0+UN_CH_LCD_COLUMN) & 0x0F;
		Lcd4_Cmd(UN_CH_LCD_VAR3);
		Lcd4_Cmd(UN_CH_LCD_VAR4);
	}
}

/*
*Function name : Lcd4_Init
*Parameters	   : NONE
*return		   : void
*purpose       : initialization of LCD
*
*/
void Lcd4_Init()
{
	Lcd4_Port(0x00);
	_delay_ms(20);
	Lcd4_Cmd(0x03);
	_delay_ms(5);
	Lcd4_Cmd(0x03);
	_delay_ms(11);
	Lcd4_Cmd(0x03);
	Lcd4_Cmd(0x02);
	Lcd4_Cmd(0x02);
	Lcd4_Cmd(0x08);
	Lcd4_Cmd(0x00);
	Lcd4_Cmd(0x0C);
	Lcd4_Cmd(0x00);
	Lcd4_Cmd(0x06);
}

/*
*Function name : Lcd4_Write_Char
*Parameters	   : Unsigned char
*return		   : void
*purpose       : WRITING CAHR ON LCD
*
*/
void Lcd4_Write_Char(unsigned char UN_CH_LCD_CHAR)
{
	unsigned char UN_CH_LCD_VAR5 = 0 , UN_CH_LCD_VAR6 = 0 ;
	UN_CH_LCD_VAR5 = UN_CH_LCD_CHAR & 0x0F;
	UN_CH_LCD_VAR6 = UN_CH_LCD_CHAR & 0xF0;
	pinChange(RS,1);             // => RS = 1
	Lcd4_Port(UN_CH_LCD_VAR6>>4);             //Data transfer
	pinChange(EN,1);
	_delay_ms(1);
	pinChange(EN,0);
	_delay_ms(1);
	Lcd4_Port(UN_CH_LCD_VAR5);
	pinChange(EN,1);
	_delay_ms(1);
	pinChange(EN,0);
	_delay_ms(1);
}

/*
*Function name : Lcd4_Write_String
*Parameters	   : Unsigned char
*return		   : void
*purpose       : Writing a string on LCD
*
*/
void Lcd4_Write_String(unsigned char *CH_LCD_STRING_PTR)
{
	unsigned char UN_ch_LCD_COUNTER ;
	for(UN_ch_LCD_COUNTER=0;CH_LCD_STRING_PTR[UN_ch_LCD_COUNTER]!='\0';UN_ch_LCD_COUNTER++)
	{
		Lcd4_Write_Char(CH_LCD_STRING_PTR[UN_ch_LCD_COUNTER]);
	}
}

/*
*Function name : Lcd4_Shift_Right
*Parameters	   : NONE
*return		   : void
*purpose       : shifting LCD display to right
*
*/
void Lcd4_Shift_Right()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x0C);
}

/*
*Function name : Lcd4_Shift_left
*Parameters	   : NONE
*return		   : void
*purpose       : shifting LCD display to left
*
*/
void Lcd4_Shift_Left()
{
	Lcd4_Cmd(0x01);
	Lcd4_Cmd(0x08);
}
