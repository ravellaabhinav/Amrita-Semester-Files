#include <LPC214X.H>		 
void delay(void);

int main(void)
{	
	// select the pin function as GPIO
	PINSEL0 = 0x00000000; // P0.0 to P0.15 becomes GPIO
	PINSEL1 = 0x00000000; // P0.16 to P0.31 becomes GPIO
	PINSEL2 = 0x00000000; // P1.16 to P1.31 becomes GPIO
	
	IODIR0 = 0xFFFFFFFF; 		
	IODIR1 = 0xFFFFFFFF;  
  
  	while(1)
  	{		
		IOSET0 = 0xAAAAAAAA;
		IOSET1 = 0x55555555;	
		delay();
		IOCLR0 = 0xFFFFFFFF;
		IOCLR1 = 0xFFFFFFFF;	
		delay();

	}
}
void delay(void)
{
	int i;
	for(i=0; i<=100000;i++)
	{};
	
}