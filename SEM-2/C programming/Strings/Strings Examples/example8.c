#include<string.h>
#include<stdio.h>

#define MAX_STRING_LENGTH 100

int main() {

  /* this example is useful for your homework:
   * it read an input line and extract the first
   * four words.
   *
   * What happens if you enter more than four words?
   * What if there are less than four words?
   *
   * This example is useful for the shell assignment.
   * It might be a reasonable assumption that each
   * command has less than a fixed number of paramters.
   * However, for a real shell you don't want to make 
   * this restriction.
   */

  char S[MAX_STRING_LENGTH];
  char A0[MAX_STRING_LENGTH];
  char A1[MAX_STRING_LENGTH];
  char A2[MAX_STRING_LENGTH];
  char A3[MAX_STRING_LENGTH];

  int n;
  
  /* gets reads an entire line from the input */
  gets(S);
  
  /* read four strings from array of character S */
  n = sscanf(S,"%s %s %s %s",A0,A1,A2,A3);
  
  printf("strings read:\t%d\n",n);
  printf("A0:\t%s\n",A0);
  printf("A1:\t%s\n",A1);
  printf("A2:\t%s\n",A2);
  printf("A3:\t%s\n",A3);

}
