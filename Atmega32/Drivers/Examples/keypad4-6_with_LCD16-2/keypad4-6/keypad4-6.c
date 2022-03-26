/*
 * keypad4_6.c
 *
 * Created: 3/26/2022 12:13:11 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 


#include "keypad4-6.h"

/*
*Function name : vKeypadInit
*Parameters	   : void
*return		   : void
*purpose       : initialize keypad rows as output
*				 and lines as input
*/
void v_Keypad_Init(void)
{
	// Set all ROWS as output
	ROW0_DDR |= (1U<<ROW0);
	ROW1_DDR |= (1U<<ROW1);
	ROW2_DDR |= (1U<<ROW2);
	ROW3_DDR |= (1U<<ROW3);
	// Set all LINES as input
	LINE0_DDR &=~(1U<<LINE0);
	LINE1_DDR &=~(1U<<LINE1);
	LINE2_DDR &=~(1U<<LINE2);
	LINE3_DDR &=~(1U<<LINE3);
	LINE4_DDR &=~(1U<<LINE4);
	LINE5_DDR &=~(1U<<LINE5);
	// Enable PULLUP
	LINE0_PULLUP |=(1U<<LINE0);
	LINE1_PULLUP |=(1U<<LINE1);
	LINE2_PULLUP |=(1U<<LINE2);
	LINE3_PULLUP |=(1U<<LINE3);
	LINE4_PULLUP |=(1U<<LINE4);
	LINE5_PULLUP |=(1U<<LINE5);
	// Set all ROWS as HIGH
	ROW0_PORT |=(1U<<ROW0);
	ROW1_PORT |=(1U<<ROW1);
	ROW2_PORT |=(1U<<ROW2);
	ROW3_PORT |=(1U<<ROW3);
}


/*
*Function name : ucKeypadScan
*Parameters	   : void
*return		   : unsigned char
*purpose       : scan the keypad and return the pressed key
*				and returns null if no key pressed
*/
uint8_t u8_cKeypad_Scan(void)
{
	uint8_t row=0,input=0;
	// loop for ROW
	for (row=0;row<4;row++)
	{
		//set all rows high
		ROW0_PORT |=(1U<<ROW0);
		ROW1_PORT |=(1U<<ROW1);
		ROW2_PORT |=(1U<<ROW2);
		ROW3_PORT |=(1U<<ROW3);
		//clear row number from iteration
		switch(row)
		{
			case 0:ROW0_PORT &=~(1U<<ROW0);
			break;
			case 1:ROW1_PORT &=~(1U<<ROW1);
			break;
			case 2:ROW2_PORT &=~(1U<<ROW2);
			break;
			case 3:ROW3_PORT &=~(1U<<ROW3);
			break;
		}
		//read the input
		input  = (((LINE0_PIN&(1U<<LINE0))>>LINE0));
		input |= (((LINE1_PIN&(1U<<LINE1))>>LINE1)<<1);
		input |= (((LINE2_PIN&(1U<<LINE2))>>LINE2)<<2);
		input |= (((LINE3_PIN&(1U<<LINE3))>>LINE3)<<3);
		input |= (((LINE4_PIN&(1U<<LINE4))>>LINE4)<<4);
		input |= (((LINE5_PIN&(1U<<LINE5))>>LINE5)<<5);
		//0x3F
		//if it was input
		if(ALL_LINES != 1)
		{
			//wait till the input is gone
			while(ALL_LINES != 1);
			break;
		}
	}
	if(row == 4)
	{
		return 0;
	}
	//switch the rows
	switch(row)
	{
		case 0 :
		switch(input)
		{
			case 0x1F : return '/';
			case 0x2F : return '*';
			case 0x37 : return '9';
			case 0x3B : return '8';
			case 0x3D : return '7';
			case 0x3E : return 'C';
		}
		case 1 :
		switch(input)
		{
			case 0x1F : return 'M';
			case 0x2F : return '-';
			case 0x37 : return '6';
			case 0x3B : return '5';
			case 0x3D : return '4';
			case 0x3E : return 'S';
		}
		case 2 :
		switch(input)
		{
			case 0x1F : return 'A';
			case 0x2F : return '+';
			case 0x37 : return '3';
			case 0x3B : return '2';
			case 0x3D : return '1';
			case 0x3E : return 'P';
		}
		case 3 :
		switch(input)
		{
			case 0x1F : return 'B';
			case 0x2F : return '+';
			case 0x37 : return '=';
			case 0x3B : return '.';
			case 0x3D : return '0';
			case 0x3E : return 'R';
		}
	}
	return 0;
}