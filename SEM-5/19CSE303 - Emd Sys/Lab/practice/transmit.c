#include <LPC213x.H>

int main(void)
{   
    // select the pin function as GPIO
    PINSEL0 = 0x00000005;



        // make P0.12 P0.13  as GPIO   ( connected to Relay 1 )
       // make it as output
    IODIR0 = (1<<12);
  IODIR0 = (1<<13);


//Set 8 bits - no Parity - 1 Stop bit for Txsion  & DLAB = 1
		 U0LCR = 0x83;  	// Line Control Register 
//Set Baud Rate as 9600 bps   -   15MHz   VPB Clock   (PCLK)
		U0DLL = 97;	// Divisor Latch LSB
//Disable Access To Divisor Latches 
		 U0LCR = 0x03;	// DLAB = 0  Bit – 7
//5) Wait until UART0 ready to send character
		 while(!(U0LSR & 0x20)); // Line Status Register – THRE
//Sent a character to UART Transmit Register
	U0THR = 'a';
}