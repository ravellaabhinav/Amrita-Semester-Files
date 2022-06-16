#include<lpc214x.h>
#include "delay.h"
unsigned int adc_data;
void adc_ini()
{
	PINSEL1 &= 0xDFFFFFFF;
	PINSEL1 |= 0x10000000;
	PCONP |= (unsigned long) (0x00000001)<<12;
}
unsigned long int adc_read0(char channel)
{
	unsigned long rec;
	//CLKDIV = PCLK/8, BURST=0, CLKS=11/10bits, PDN=1
	AD0CR = 0x00200700;
	switch(channel)
	{
		case 0:
			AD0CR |= 0x00000001;
		break;
		case 1:
			AD0CR |= 0x00000002;
		break;
		case 2:
			AD0CR |= 0x00000004;
		break;
		case 3:
			AD0CR |= 0x00000008;
		break;
		case 4:
			AD0CR |= 0x00000010;
		break;
		case 5:
			AD0CR |= 0x00000020;
		break;
		case 6:
			AD0CR |= 0x00000040;
		break;
		case 7:
			AD0CR |= 0x00000080;
		break;
		default:
			AD0CR |= 0x00000001;
		break;
	}
	AD0CR |= (1<<24);
	while(!(AD0GDR & 0x80000000));
	rec = AD0GDR;
	AD0CR &= 0xF8FFFFFF;
	rec = rec>>6;
	rec = rec &0x3FF;
	return (rec);
}
int main()
{
	PINSEL0=0x00000000;
	PINSEL2 = 0X00;
	IO1DIR=0xFFFFFFFF;
	adc_ini();
	while(1)
	{
		adc_data = adc_read0(3);
		IOPIN1 = adc_data<<16;
	}
}