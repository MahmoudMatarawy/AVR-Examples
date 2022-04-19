/*
 * ADC.c
 *
 * Created: 4/19/2022 7:11:11 AM
 * Author: Mahmoud Sarhan
 * Email  : eng.mahmoud.adel94@gmail.com
 */

 #include "ADC.h"


 int main(void)
 {
	 DDRC = 0xff;
	 ADC_CONFIG s1;
	 s1.ref_selection = AVCC;
	 s1.prescaler_selection = PRESCALER_2;
	 ADC_INIT(&s1);
	 uint16_t x = 0 ;
	 while (1)
		{
			x = ADC_READ(0);
			if (x!=0)
			{
				PORTC = x ;
			}
			_delay_ms(10000);
		}
 }

