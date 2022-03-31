/*
 * Calc.c
 *
 * Created: 3/26/2022 6:21:15 PM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#include "Calc.h"
unsigned int power (unsigned int base , unsigned int factor)
{
	if (factor==0)
	{
		return 1 ;
	}
	return base * power(base,factor-1);
}
void print_res(float res)
{
	unsigned char out_1[10];
	out_1[0] = '0';
	unsigned char out_2[10];
	unsigned int sub = 0 ;
	unsigned int out_l = (int)res;
	unsigned int out_r = ((int)(res*1000))-(((int)res)*1000);
	unsigned int i = 0;
	for(i = 0; out_l!=0;i++)
	{
		sub = out_l - ((out_l/10)*10);
		out_1[i]= sub+48;
		out_l -= sub;
		out_l /=10;
	}
	if(i==0)
	{
		Lcd4_Write_Char('0');
	}
	for (int a = i-1 ; a >= 0 ; a--)
	{
		Lcd4_Write_Char(out_1[a]);
	}
	if (out_r>0)
	{
		int j = 0 ;
		for(j=0;out_r>0;j++)
		{
			sub = out_r - ((out_r/10)*10);
			out_2[j] = sub +48;
			out_r -= sub ;
			out_r/=10;
		}
		Lcd4_Write_Char('.');
		switch(j)
		{
			case 3 : 
			for(int a = j-1 ; a >=0 ; a--)
			{
				Lcd4_Write_Char(out_2[a]);
			}
			break;
			case  2 : 
			Lcd4_Write_Char('0');
			for(int a = j-1 ; a >=0 ; a--)
			{
				Lcd4_Write_Char(out_2[a]);
			}
			break;
			case 1 :
			Lcd4_Write_Char('0');
			Lcd4_Write_Char('0');
			for(int a = j-1 ; a >=0 ; a--)
			{
				Lcd4_Write_Char(out_2[a]);
			}
			break;
		}
		
	}
}
float store_num(unsigned char *str , unsigned int start , unsigned int end)
{
	float in = 0 ;
	unsigned int a = 0 ;
	for(int i = start ; i<=end ; i++)
	{
		if (str[i]=='.')
		{
			a = i;
		}
	}
	if (a==0)
	{
		for(int i = start ; i <= end ; i++)
		{
			in+= (str[i]-48)*power(10,end-i);
		}
	}
	else{
		for(int i = start ; i< a ; i++)
		{
			in+= (str[i]-48)*power(10,end-1-i);
		}
		for(int i = a+1 ; i<= end ; i++)
		{
			in+= (str[i]-48)*power(10,end-i);
		}
		in /= power(10,a);
	}
	return in ;
}
float root(unsigned char *str,unsigned int ind)
{
	float in=0;
	in = store_num(str,0,ind-1);
	in = sqrtf(in);
	return in ;
}
float precentage(unsigned char *str,unsigned int ind)
{
	float in=0;
	in = store_num(str,0,ind-1);
	in/=100;
	return in ;
}
void clean(unsigned char *str)
{
	for(int i = 0 ; str[i]!='\0' ; i++)
	{
		str[i] = '\0';
	}
}
int ope(unsigned char op)
{
	switch (op)
	{
		case  '+' : return 1 ;
		case  '-' : return 1 ;
		case  '*' : return 1 ;
		case  '/' : return 1 ;
		case  '=' : return 1 ;
	}
	return 0 ;
}
void split(unsigned char *str,unsigned char *op , float *n)
{
	int pr = 0 ;
	int ind = 0 ;
	for (int i = 0 ; str[i]!='\0';i++)
	{
		if (ope(str[i])==1)
		{
			n[ind] = store_num(str,pr,i-1);
			op[ind] = str[i];
			pr = i + 1 ;
			ind ++ ;
		}
	}
}
void rearr(unsigned int c, float *n,unsigned char *op)
{
	for(int i = c ; n[i] != '\0' ; i++ )
	{
		n[i+1]=n[i+2];
		n[i+2]='\0';
		op[i]=op[i+1];
		op[i+1]='\0';
	}
}
int calc_ml_di(unsigned char *op , float * n)
{
	if (op[0] == '=')
	{
		return 0 ;
	}
	for(int i = 0 ; op[i]!='\0' ; i++)
	{
		switch(op[i])
		{
			case '*' :
			n[i] *= n[i+1];
			rearr(i,n,op);
			return calc_ml_di(op,n);
			break;
			case '/' :
			n[i] /= n[i+1];
			rearr(i,n,op);
			return calc_ml_di(op,n);
			break;
		}
	}
	return 0 ;
}
int calc_add_sub(unsigned char *op , float * n)
{
	if (op[0] == '=')
	{
		return 0 ;
	}
	for(int i = 0 ; op[i]!='\0' ; i++)
	{
		switch(op[i])
		{
			case '+' :
			n[i] += n[i+1];
			rearr(i,n,op);
			return calc_add_sub(op,n);
			break;
			case '-' :
			n[i] -= n[i+1];
			rearr(i,n,op);
			return calc_add_sub(op,n);
			break;
		}
	}
	return 0 ;
}
float calculate_res(unsigned char*str,float ress , unsigned char fi_op)
{
	float n[100];
	unsigned char op[100];
	split(str,op,n);
	if (fi_op !='\0')
	{
		switch(fi_op)
		{
			case  '-' : n[0]  *=(-1) ;break;
			case  '*' : n[0]  *= ress ; break;
			case  '/' : n[0]   = ress/n[0] ; break;
		}
	}
	calc_ml_di(op,n);
	calc_add_sub(op,n);
	if (fi_op !='\0')
	{
		switch(fi_op)
		{
			case  '+' : n[0] += ress ;break;
		}
	}
	return n[0];
}

unsigned char input[100];
unsigned int i_c=0;
unsigned char x=0;
float res = 0 ;
unsigned char f_op = '\0';
void clean_index(void)
{
	clean(input);
	i_c=0;
}
void clean_all(void)
{
	clean(input);
	res = 0 ;
	i_c=0;
	Lcd4_Clear();
	f_op = '\0';
}
void Calc_main(void)
{
	while (res == 0)
	{
		x=u8_cKeypad_Scan();
		if (x!=0)
		{
			switch(x)
			{
				case 'C' : clean_all();break;
				case 'R' :
				if (i_c > 0)
				{
					Lcd4_Clear();
					Lcd4_Write_String("Root(");
					Lcd4_Write_String(input);
					Lcd4_Write_Char(')');
					res = root(input,i_c);
					Lcd4_Set_Cursor(2,0);
					Lcd4_Write_Char('=');
					print_res(res);
					clean_index();
				}
				break;
				case 'P' :
				if (i_c > 0)
				{
					Lcd4_Clear();
					Lcd4_Write_String("Prec(");
					Lcd4_Write_String(input);
					Lcd4_Write_Char(')');
					Lcd4_Set_Cursor(2,0);
					Lcd4_Write_Char('=');
					res = precentage(input,i_c);
					print_res(res);
					clean_index();
				}
				break;
				case '=' :
				if (i_c > 0)
				{
					input[i_c] = x;
					Lcd4_Set_Cursor(2,0);
					Lcd4_Write_Char('=');
					res = calculate_res(input,res,f_op);
					print_res(res);
					clean_index();
					f_op = '\0';
				}
				break;
				case '+' :
				if (i_c > 0)
				{
					if (ope(input[i_c-1])==1)
					{
						input[i_c-1] = x;
						Lcd4_Clear();
						Lcd4_Write_String(input);
					}
					else{
						Lcd4_Write_Char(x);
						input[i_c] = x;
						i_c++;
					}
				}
				else
				{
					Lcd4_Clear();
					Lcd4_Write_Char(x);
					f_op = x ;
				}
				break;
				case '-' :
				if (i_c > 0)
				{
					if (ope(input[i_c-1])==1)
					{
						input[i_c-1] = x;
						Lcd4_Clear();
						Lcd4_Write_String(input);
					}
					else{
						Lcd4_Write_Char(x);
						input[i_c] = x;
						i_c++;
					}
				}
				else
				{
					Lcd4_Clear();
					Lcd4_Write_Char(x);
					f_op = x ;
				}
				break;
				case '*' :
				if (i_c > 0)
				{
					if (ope(input[i_c-1])==1)
					{
						input[i_c-1] = x;
						Lcd4_Clear();
						Lcd4_Write_String(input);
					}
					else{
						Lcd4_Write_Char(x);
						input[i_c] = x;
						i_c++;
					}
				}
				break;
				case '/' :
				if (i_c > 0)
				{
					if (ope(input[i_c-1])==1)
					{
						input[i_c-1] = x;
						Lcd4_Clear();
						Lcd4_Write_String(input);
					}
					else{
						Lcd4_Write_Char(x);
						input[i_c] = x;
						i_c++;
					}
				}
				break;
				case 'M' : break; 
				case 'S' : break;
				case 'A' : break;
				case 'B' : break;
				default:
				input[i_c] = x;
				i_c++;
				Lcd4_Write_Char(x);
				break;
			}
		}
	}
	while (res !=0)
	{
		x=u8_cKeypad_Scan();
		if (x!=0)
		{
			switch(x)
			{
				case 'C' : clean_all();break;
				case '=' : 
				if (i_c > 0)
				{
					input[i_c] = x;
					Lcd4_Set_Cursor(2,0);
					Lcd4_Write_Char('=');
					res = calculate_res(input,res,f_op);
					print_res(res);
					clean_index();
					f_op = '\0';
				}
				break;
				case 'R' :
				Lcd4_Clear();
				Lcd4_Write_String("Root(");
				print_res(res);
				Lcd4_Write_Char(')');
				res = sqrtf(res);
				Lcd4_Set_Cursor(2,0);
				Lcd4_Write_Char('=');
				print_res(res);
				clean_index();
				break;
				case 'P' :
				Lcd4_Clear();
				Lcd4_Write_String("Prec(");
				print_res(res);
				Lcd4_Write_Char(')');
				res /= 100;
				Lcd4_Set_Cursor(2,0);
				Lcd4_Write_Char('=');
				print_res(res);
				clean_index();
				break;
				case '+' :
				Lcd4_Clear();
				print_res(res);
				Lcd4_Write_Char(x);
				f_op = x;
				break;
				case '-' :
				Lcd4_Clear();
				print_res(res);
				Lcd4_Write_Char(x);
				f_op = x;
				break;
				case '*' :
				Lcd4_Clear();
				print_res(res);
				Lcd4_Write_Char(x);
				f_op = x;
				break;
				case '/' :
				Lcd4_Clear();
				print_res(res);
				Lcd4_Write_Char(x);
				f_op = x;
				break;
				case 'M' : break;
				case 'S' : break;
				case 'A' : break;
				case 'B' : break;
				default:
				input[i_c] = x;
				i_c++;
				Lcd4_Write_Char(x);
				break;
			}
		}
	}
}