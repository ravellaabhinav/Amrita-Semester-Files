/** C program to fetch the values of hours,
 * minutes and seconds from the string and
 * print it using integer variables
*/

#include <stdio.h>

// function to validate the time
int ValidateTime(int hh , int mm , int ss)
{
    int ret=0;
    
    if(hh>24)   ret=1;
    if(mm>60)   ret=1;
    if(ss>60)   ret=1;
    
    return ret;
}

// main function
int main()
{
    // declare a char buffer
    char string[100]={0};
    
    // declare some local int variables
    int ret=0,hour=0,min=0,sec=0;
    
    printf("\nEnter the time in \"hh:mm:ss\" format : ");
    fgets(string,100,stdin);
    
    // fetch the hour,min and sec values from the
    // string and then store it in int variables
    // in order to validate them
    sscanf(string , "%d:%d:%d" , &hour,&min,&sec);
    
    //printf("\nHH : %d MM : %d SS : %d",hour,min,sec);
    
    // validate the time
    ret = ValidateTime(hour,min,sec);
    if(ret)
    {
        printf("\nInvalid Time. Try Again.\n");
    }
    else
    {
        printf("\nThe Time is : %d:%d:%d\n",hour,min,sec);
    }
    return 0;
}

