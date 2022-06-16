#include<stdio.h>
#include<string.h>

#define MAX_STRING_LEN 80

int main() {
  
  /* Warning: Strings aren't regular variables
   * You've to be careful with string comparison
   * and assignments.
   */

  char* S1 = "AAAAAAAAAA";
  char* S2 = "AAAAAAAAAA";
  
  int cmp1, cmp2, cmp3, cmp4;
  
  cmp1 = (S1 == S2);
  cmp2 = strcmp(S1,S2);
  
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);
  printf("S1 == S2:\t%d\n",cmp1);
  printf("strcmp(S1,S2):\t%d\n",cmp2);

  S2 = S1;
  cmp3 = (S1 == S2);
  cmp4 = strcmp(S1,S2);
  printf("\nafter assignment\n");
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);
  printf("S1 == S2:\t%d\n",cmp3);
  printf("strcmp(S1,S2):\t%d\n",cmp4);
}
