# Guess-What Program

Test Cases:

```
$ ./main
$ ./main --list red green blue
$./main --file numbers.txt

```

## main.c

```c

#include <stdio.h>
#include "welcome.h"
#include "help.h"
#include "cli.h"
#include "play.h"

int main(int argc, char *argv[]) {
  welcome();
  cli(argc, argv);

  play(cli_get_list(), cli_get_list_size());
  printf("\n");

  return 0;
}

```

## cli.c

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cli.h"
#include "help.h"


static int list_size;
int cli_get_list_size(){
    return list_size;
} 

static char **word_list;
char **cli_get_list(){
  return word_list;
}

void cli(int argc, char *argv[]){

  
  if(1 == argc){
    help(argv[0]);
    return;
  }

  char *dash_cmd = argv[1];
  if (0 == strcmp("--list",dash_cmd)){

    if(argc < 5){
      int errorCode = 404;
      fprintf(stderr, "ERROR %d : Not Enough Words", errorCode);
      exit(1);
    }

    list_size = argc - 2;
    word_list = &argv[2]; 
  }
  
  if(0 == strcmp("--file",dash_cmd)){

    char *fileName = argv[2];
    FILE *file = fopen(fileName, "r");
    if(NULL == file){
      perror("fopen");
      exit(4);
    }

    char word[10];
    int result = fscanf(file, "%s", word);

    while(result != EOF){
      printf("%s\n", word);
      result = fscanf(file,"%s", word);
    }
    

    fclose(file);
    return;
  }

  help(argv[0]);
  
}

```

## help.c

```c

#include <stdio.h>
#include "help.h"

void help(char *cmd){
printf("\nUsage Info: \n"
        "%s -- help\n"
        "%s -- file FILENAME\n"
        "%s -- list word1 word 2 ...\n",
        cmd,cmd,cmd
        );
  
}

```

## play.c

```c

#include <stdio.h>
#include "play.h"
#include "cli.h"
#include <time.h>
#include <stdlib.h>

void play(char **word_list, int list_size){

  printf("Guess What word from these words!\n");
  for(int i = 0; i < list_size; i++){
    printf("%d-%s ", i, word_list[i]);
    }

    printf("\n");

  int num_tries = 0;
  srand(time(NULL)); //seed the random number generator

  int goal = rand() % list_size;
  printf("goal: %d\n", goal);
  int choice;
  
  do{
    num_tries++;
    printf("Your Choice: ");
    scanf("%d", &choice);
    
  } while((goal != choice) && (num_tries < 3));

  if (goal != choice){
    printf("Sorry you lost!\n");
  }
  else{
    printf("You Win!\n");
  }
}

```

## welcome.c

```c

#include <stdio.h>
#include "welcome.h"

#define PROG_NAME "Guess What"
#define VERSION "VERSION 3.0.0"
#define DEVELOPER "Ford Culallad"

void welcome(){
  //printf("%s", __FUNCTION__);
  printf("%s\n", PROG_NAME);
  printf("%s\n", VERSION);
  puts("Copyright (c) 2024");
  printf("%s\n", DEVELOPER);
}

```

