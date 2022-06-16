
#include<LPC214x.h>
#include<stdio.h>


void transmit(unsigned char ch)
{
	while(!(UOLSR & 0x20));
	UOTHR=ch;
}

void main()
{
	int i;
	unsigned char temp[30]="Welcome..";
	
	PINSEL0=5;
	U0LCR=0x83;
	U0DLM=0x00;
	U0DLL=978;
	U0LCR=0x03;
	for(i=0;temp[i]!='\0';i++)
	{
		transmit(temp[i]);
	}
}