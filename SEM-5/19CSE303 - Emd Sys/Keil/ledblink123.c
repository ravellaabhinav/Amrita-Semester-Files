#include<LPC214X.H>
 void delay(void);

 int main(void)
 {
	 int i;
	 
	 PINSEL0=00;
	 IODIR0 |= (0xf << 4);
		
		 while(1)
	 {
		 for(i=0; i<=15; i++)
		 {
				IOPIN0 = (i << 4);
				delay();
		 }
		 for(i=15; i>=0; i--)
		 {
				IOPIN0 = (i << 4);
				delay();
		 }
	 }
 }


 void delay(void)
{
	 int s;
	for(s=0;s<100000;s++)
	{
	 	
	}
}