#include<stdio.h>
#include<string.h>

#define MAX_STRING_LEN 80

int main() {
  
  /* strings can be read using scanf with %s
   * string.h contains many useful functions
   * for working with strings:
   *   strcmp for string comparisons
   *   strcpy to copy strings
   *   ...
   *
   * Check what happens if your input contains
   * spaces, tabs, etc
   *
   */

  char S1[MAX_STRING_LEN];
  char S2[MAX_STRING_LEN];
  
  int i, l;

  printf("String:\t");
  scanf("%s",S1);

  /* we need to copy all the characters, and
   * the final NULL character!
   */

  l = strlen(S1);
  /* rather than writing this loop
     we could also write strcpy(S2,S1) */

  for (i = 0; i < l+1; ++i)
    S2[i] = S1[i];


  /* change original S1 */
  S1[0] = S1[1] = S1[2] = '*';
  S1[3] = 0;

  /* print both strings */
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);

}
