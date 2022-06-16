#include <LPC214X.H>
void delay(insigned int x)
{
int i;
for(i=0;i<x;i++);
}
void main()
{
	while(1){
		P1=~P1;
		delay(1000);
	}
}
