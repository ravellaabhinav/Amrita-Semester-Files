#include<stdio.h>
#include<string.h>

#define MAX_STRING_LEN 80

int main() {
  
  /* Warning: Strings aren't regular variables
   * You've to be careful with string comparison
   * and assignments.
   */

  char* S1 = "AAAAAAAAAA";
  char* S2 = "BBBBBBBBBB";
  
  int i, l;

  /* assign S1 to S2 */
  S2 = S1;

  /* change S1 */
  S1[0] = S1[1] = S1[2] = '*';
  S1[3] = 0;

  /* print both strings */
  printf("S1:\t%s\n",S1);
  printf("S2:\t%s\n",S2);

}
