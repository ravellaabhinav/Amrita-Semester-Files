#include <lpc214x.h>

void delay_ms(unsigned int count)
{
  unsigned int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<3000;i++);
  }
}

/* start the main program */
int main() 
{
    PINSEL2 = 0x000000;  //Configure the P1 Pins for GPIO;
    IODIR1 = 0xffffffff; //Configure the P1 pins as OUTPUT;

  while(1)
    {
			 IOCLR0 |=0XFFFfffff;
				 delay_ms(500);
       IOSET1 = (1<<24);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<24);     // Make all the Port pins as low  
			
			IOSET1 = (1<<23);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<23);     // Make all the Port pins as low  
			
			IOSET1 = (1<<22);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<22);     // Make all the Port pins as low  
			
			IOSET1 = (1<<21);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<21);     // Make all the Port pins as low  
				 
			IOSET1 = (1<<20);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<20);     // Make all the Port pins as low  

			//
			IOSET1 = (1<<21);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<21);     // Make all the Port pins as low  
			
			IOSET1 = (1<<22);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<22);     // Make all the Port pins as low  
			
			IOSET1 = (1<<23);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<23);     // Make all the Port pins as low  
			
			IOSET1 = (1<<24);     // Make all the Port pins as high  
         delay_ms(500);
       IOCLR1 = (1<<24);     // Make all the Port pins as low  
				 
         delay_ms(500);
       
    }
}