#include <lpc214x.h>

void delay_ms(unsigned int count)
{
  unsigned int j=0,i=0;
  for(j=0;j<count;j++)
  {
    for(i=0;i<3000;i++);
  }
}

int main() 
{
    PINSEL2 = 0x000000;  
    IODIR1 = 0xffffffff;

  while(1)
    {
       IOSET1 = 0xffffffff;
         delay_ms(1000);

       IOCLR1 = 0xffffffff;  
         delay_ms(1000);
    }
}