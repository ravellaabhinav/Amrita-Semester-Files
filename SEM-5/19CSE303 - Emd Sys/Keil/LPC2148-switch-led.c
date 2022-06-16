#include <LPC214X.H>

int main(void)
{   
    // select the pin function as GPIO
    PINSEL0 = 00;

    // Set the port direction (P0.3 as input)
    // P0.3 connected to EXINT1 key
    IODIR0 = (0<<3);

        // make P0.12 as GPIO   ( connected to Relay 1 )
       // make it as output
    IODIR0 = (1<<12);
	
	x = printf(" CSE E");
	 a = 2;

    while(1)                           0x00000008  = 0000 0000 0000 0000 0000 0000 0000 1000 &
		                                                 xxxx xxxx xxxx xxxx xxxx xxxx xxxx 1xxx
                                                    -------------------------------------------		
		                                                 yyyy yyyyy yyyyy yy yyy yyy y yy yyy
    {   
        if(IOPIN0 & 0x00000008)  // Test P0.3 key     
        {   
            IOCLR0 = 0x00001000; // Relay1 off         0x00001000; 0000 0000 0000 0000 0001 0000 0000 0000             
        }
        else
        {
						IOSET0 = 0x00001000; // Relay1 on        
				}
    }  
}