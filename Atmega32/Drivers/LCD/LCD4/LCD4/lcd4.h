/*
 * lcd4.h
 *
 * Created: 3/13/2022 2:56:26 AM
 *  Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#ifndef LCD4_H_
#define LCD4_H_
#ifndef F_CPU
#define F_CPU 12000000UL // 12 MHz clock speed
#endif
#include <util/delay.h>
#include <avr/io.h>
 void pinChange(int a, int b);
 void Lcd4_Port(unsigned char UN_CH_LCD_VAR1);
 void Lcd4_Cmd(unsigned char UN_CH_LCD_VAR1);
 void Lcd4_Clear();
 void Lcd4_Set_Cursor(unsigned char UN_CH_LCD_ROW, unsigned char UN_CH_LCD_COLUMN);
 void Lcd4_Init();
 void Lcd4_Write_Char(unsigned char UN_CH_LCD_CHAR);
 void Lcd4_Write_String(char *CH_LCD_STRING_PTR);
 void Lcd4_Shift_Right();
 void Lcd4_Shift_Left();




#endif /* LCD4_H_ */