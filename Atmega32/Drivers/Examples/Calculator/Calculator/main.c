/*
 * Calculator.c
 *
 * Created: 3/25/2022 11:55:07 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 

#include "Calc.h"

int main(void)
{
	DDRA = 0xff;
	DDRB = 0xff;
	Lcd4_Init();
	v_Keypad_Init();
	while(1)
	{
		Calc_main();
	}
	/*unsigned char input[100];
	int i_c=0;
	unsigned char x=0;
	float res = 0 ;
	unsigned char f_op = '\0';
	while (1)
	{
		while (res == 0)
		{
			x=u8_cKeypad_Scan();
			if (x=='C')
			{
				clean(input);
				res = 0 ;
				i_c=0;
				Lcd4_Clear();
				f_op = '\0';
			}
			else if (x=='=')
			{
				input[i_c] = x;
				i_c=0;
				f_op = '\0';
				Lcd4_Set_Cursor(2,0);
				res = calculate_res(input);
				print_res(res);
				clean(input);
				i_c=0;
			}
			else if (x=='R')
			{
				Lcd4_Clear();
				Lcd4_Write_String("root(");
				Lcd4_Write_String(input);
				Lcd4_Write_Char(')');
				res = root(input,i_c);
				Lcd4_Set_Cursor(2,0);
				print_res(res);
				i_c=0;
				clean(input);
			}
			else if(x=='P')
			{
				Lcd4_Clear();
				Lcd4_Write_String("Prec(");
				Lcd4_Write_String(input);
				Lcd4_Write_Char(')');
				Lcd4_Set_Cursor(2,0);
				res = precentage(input,i_c);
				print_res(res);
				i_c=0;
				clean(input);
			}
			else if(x!=0)
			{
				input[i_c] = x;
				i_c++;
				Lcd4_Write_Char(x);
			}
		}
		while (res != 0)
		{
			x=u8_cKeypad_Scan();
		}
		else if (x=='=')
		{
			else if (f_op = '\0')
			{
				Lcd4_Clear();
				print_res(res);
			}
			else if (f_op !='\0')
			{
				Lcd4_Clear();
				switch(f_op)
				{
					case '+' : res += calculate_res(input);break;
					case '-' : res -= calculate_res(input);break;
					case '/' : res /= calculate_res(input);break;
					case '*' : res *= calculate_res(input);break;
				}
			}
		}
		else if(x!=0)
		{
			input[i_c] = x;
			i_c++;
			Lcd4_Write_Char(x);
		}
	}*/
}

