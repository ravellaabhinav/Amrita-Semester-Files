#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 80
#define TABLE_SIZE 20

int main() {

  char command[MAX_STRING_LENGTH];
  char word[MAX_STRING_LENGTH];
  char A[TABLE_SIZE][MAX_STRING_LENGTH];

  int i;

  /* initialization */
  for (i = 0; i < TABLE_SIZE; ++i)
    strcpy(A[i],"");
  
  do {
    printf("$ ");
    scanf("%s",command);

    if (strcmp(command,"list") == 0) {
      for (i = 0; i < TABLE_SIZE; ++i) 
	printf("%d %s\n",i,A[i]);
      
    } else if (strcmp(command,"insert") == 0) {
      /* add word to the array */
      scanf("%s",word);
      i = 0;
      while ((i < TABLE_SIZE) && (strcmp("",A[i]) != 0)) ++i;
      if (i < TABLE_SIZE)
	strcpy(A[i],word);
      
    } else if (strcmp(command,"delete") == 0 ) {
      /* remove the word from our array */
      scanf("%s",word);
      i = 0;
      while ((i < TABLE_SIZE) && (strcmp(word,A[i]) != 0)) ++i;
      if (i < TABLE_SIZE)
	strcpy(A[i],"");
    }
    
  } while (strcmp(command,"exit") != 0);
  
}
