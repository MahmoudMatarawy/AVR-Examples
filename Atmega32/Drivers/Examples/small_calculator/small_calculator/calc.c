/*
 * calc.c
 *
 * Created: 3/15/2022 10:26:03 PM
 *  Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */ 
#include "calc.h"
#include "keypad.h"
#include "lcd4.h"
#include <math.h>
#define high 1
#define low 0
void pir(char *opp,int *pr)
{
	for(int i = 0 ; opp[i]!='=' ; i++)
	{
		if(opp[i]=='+')
		{
			pr[i] = low;
		}
		if(opp[i]=='-')
		{
			pr[i] = low;
		}
		if(opp[i]=='*')
		{
			pr[i] = high;
		}
		if(opp[i]=='/')
		{
			pr[i] = high;
		}
	}
}
void rearr(int c,float *n,char *op,int pr[])
{
	for(int i = c ; n[i] != '\0' ; i++ )
	{
		n[i+1]=n[i+2];
		n[i+2]='\0';
		op[i]=op[i+1];
		op[i+1]='\0';
		pr[i]=pr[i+1];
		pr[i+1]='\0';
	}
}

int calc_ml_d(float *n , char *op,int *pr)
{
	if(op[0] == '=')
	{
		return 0;
	}
	for(int i = 0 ; op[i] != '=' ; i++)
	{
		if(pr[i]==high)
		{
			if(op[i]=='*')
			{
				n[i] *= n[i+1];
			}
			if(op[i]=='/')
			{
				n[i] /= n[i+1];
			}
			rearr(i,n,op,pr);
			return calc_ml_d(n,op,pr);
		}
	}
	return 0;
}
int calc_p_mi(float *n , char *op,int *pr)
{
	if(op[0] == '=')
	{
		return 0;
	}
	for(int i = 0 ; op[i] != '=' ; i++)
	{
		if(pr[i]==low)
		{
			if(op[i]=='+')
			{
				n[i] += n[i+1];
			}
			if(op[i]=='-')
			{
				n[i] -= n[i+1];
			}
			rearr(i,n,op,pr);
			return calc_p_mi(n,op,pr);
		}
	}
	return 0;
}
int ope(char n)
{
	switch(n)
	{
		case '+' : return 1 ;
		case '-' : return 1 ;
		case '*' : return 1 ;
		case '/' : return 1 ;
		case '=' : return 1 ;
	}
	return 0 ;
}
void store_n(float *n , char *arr ,int pr , int ind , int n_c)
{
	for(int i=ind ; i>=pr ; i--)
	{
		n[n_c] += (arr[i]-48)*pow(10,ind-i);
	}
}
void split (char *arr , char *op , float *n)
{
	int op_c=0 ;
	int n_c=0;
	int pr = 0 ;
	for(int i = 0 ; arr[i]!='\0' ; i++)
	{
		if(ope(arr[i])==1)
		{
			op[op_c] = arr[i];
			op_c++;
			store_n(n,arr,pr,i-1,n_c);
			n_c++;
			pr=i+1;
		}
	}
}
void clean(char *str)
{
	for (int i = 0 ; str[i]!='\0';i++)
	{
		str[i]='\0';
	}
}
void clean_int(int *str)
{
	for (int i = 0 ; str[i]!='\0';i++)
	{
		str[i]='\0';
	}
}
void clean_float(float *str)
{
	for (int i = 0 ; str[i]!='\0';i++)
	{
		str[i]='\0';
	}
}
void calculate_res(char*input)
{
	//Lcd4_Write_String(input);
	float n[100];
	char op[100];
	split(input,op,n);
	//Lcd4_Write_String(op);
	int pr[100];
	pir(op,pr);
	calc_ml_d(n,op,pr);
	calc_p_mi(n,op,pr);
	clean_int(pr);
	clean(op);
	char out_l[10];
	int i =0;
	int sub;
	int input_l = ((int)n[0]);
	for( i = 0 ; input_l!=0 ; i++)
	{
		sub = (input_l-(input_l/10)*10);
		out_l[i] = sub +48;
		input_l -=sub;
		input_l /=10;
	}
	char out_r[10];
	int j =0;
	sub=0;
	int input_r = ((int)(n[0]*1000))-(((int)n[0])*1000);
	for( j = 0 ; input_r!=0 ; j++)
	{
		sub = (input_r-(input_r/10)*10);
		out_r[j] = sub +48;;
		input_r -=sub;
		input_r /=10;
	}
	Lcd4_Write_Char('=');
	for (int a=i-1;a>=0;a--)
	{
		Lcd4_Write_Char(out_l[a]);
	}
	if (j>0)
	{
		Lcd4_Write_Char('.');
		for (int a=j-1;a>=0;a--)
		{
			Lcd4_Write_Char(out_r[a]);
		}
	}
	clean_float(n);
}