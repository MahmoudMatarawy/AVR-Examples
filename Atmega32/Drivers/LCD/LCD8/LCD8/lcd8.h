/*
 * lcd8.h
 *
 * Created: 3/13/2022 5:44:20 PM
 * Author : Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#ifndef LCD8_H_
#define LCD8_H_
#include <avr/io.h>
#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif
#include <util/delay.h>
void pinChange(int a, int b);
void Lcd8_Port(unsigned char UN_CH_LCD_VAR1);
void Lcd8_Cmd(unsigned char UN_CH_LCD_VAR1);
void Lcd8_Clear();
void Lcd8_Set_Cursor(unsigned char UN_CH_LCD_ROW, unsigned char UN_CH_LCD_COLUMN);
void Lcd8_Init();
void Lcd8_Write_Char(unsigned char UN_CH_LCD_CHAR);
void Lcd8_Write_String(char *UN_CH_LCD_STRING_PTR);
void Lcd8_Shift_Right();
void Lcd8_Shift_Left();

#endif /* LCD8_H_ */