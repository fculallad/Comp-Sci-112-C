# String Skills

## main.c

```c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *colorsv[] = {"red", "green", "blue"};

int main(int argc, char *argv[]) {

  //PART I
  char word[] = "Hello";

  printf("sizeof: %lu\n", sizeof(word));
  printf("strlen: %lu\n\n", strlen(word));

  //PART II
  for (int i = 0; i < sizeof(word); i++){
    printf("title[%d]: %d (0x%02x) ", i, word[i], word[i]);

  if (isalpha(word[i])){
    printf("%c\n", word[i]);
  }
    else{
      printf("Not alphabetical letter");
    }    

  }  
  printf("\n\n");

  for (int i = 0; i < argc; i++){
    printf("%s\n", argv[i]);
  }
  printf("\n");

  //PART III
  
  if (argc == 1){
    puts("Please enter a color: red, green, or blue");
    printf("Example: %s red\n", argv[0]);
    return 0;
  }

  if(strcmp("red", argv[1]) == 0){
    printf("You entered red");
  } else if(strcmp("green", argv[1]) == 0){
    printf("You entered green");
  } else if(strcmp("blue", argv[1]) == 0){
    printf("You entered blue");
  } else {
    printf("BAD INPUT");
  }
  
  return 0;
}

```