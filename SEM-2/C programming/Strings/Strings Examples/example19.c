/** C program to swap adjacent characters 
* of a string but obly if it is of even 
* length
*/

#include <stdio.h>
#include <string.h>

// main function
int main()
{
	// Declare an integer pointer
	char string[30]={0};
	char c=0;
	int length=0,i=0;

	// Take string input from the user
	printf("\nEnter the string : ");
	fgest(string,30,stdin);//gets(string);

	// calculate the length of the string
	length = strlen(string);

	if(length%2==0)
	{
		for(i=0;i<length;i+=2)
		{
			c = string[i] ; 
			string[i] = string[i+1];  
			string[i+1] = c;
		}
		printf("\nAfter Swap String : %s",string);
	}
	else
	{
		printf("\nThe length of the string is Odd..\n");
	}
	
	return 0;
}

