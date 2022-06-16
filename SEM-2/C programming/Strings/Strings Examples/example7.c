#include<string.h>
#include<stdio.h>

#define MAX_STRING_LENGTH 100

int main() {
  
  /* this program reads word
   * by word and increments
   * a counter each time
   * until the string "exit"
   * is entered
   */
  
  char S[MAX_STRING_LENGTH];
  int count;
  
  count = 0;

  do {
    printf("string:\t");
    scanf("%s",S);    
    if (strcmp(S,"exit") != 0) ++count;
  } while (strcmp(S,"exit") != 0);
  
  printf("word count:\t%d\n", count);
}
