#include<string.h>
#include<stdio.h>

#define MAX_STRING_LENGTH 80

int main() {
  /* strcat is another useful command:
   * it appends a copy of a second string
   */

  char S1[MAX_STRING_LENGTH];
  char S2[MAX_STRING_LENGTH];

  strcat(S1,S2);

  printf("S1:\t");
  scanf("%s",S1);

  printf("S2:\t");
  scanf("%s",S2);

  strcat(S1,S2);

  printf("\nafter strcat(S1,S2)\n");
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);

}
