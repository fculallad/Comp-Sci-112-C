# Loop-d-loo Program

Test Case: $ ./main --start 5

## main.c


```c

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NAME "FORD CULALLAD"
#define VERSION "3.0.0"

#define START_NUM_MIN 1
#define START_NUM_MAX 10
#define END_NUM_MIN 10
#define END_NUM_MAX 100


void display_start_info(int argc){
  puts("Loop-D-Loo");
  printf("Version %s\n", VERSION);
  printf("Program by %s\n", NAME);

  time_t now = time(NULL);
  char *nowStr = ctime(&now);

  printf("%s", nowStr);
  printf("Argument Count: %d\n", argc);
  printf("\n");
  
}
int prompt(void){

  printf("WOULD YOU LIKE TO CONTINUE? (Y/N) ");
  int inpt = getchar();
  getchar();

  if('Y' == inpt || 'y' == inpt){
    return 1;
  }
  return 0;
}

void prompt_for_numbers(int *start_number, int *end_number){

  if(start_number){
    printf("Enter start number from %d to %d: ", START_NUM_MIN, START_NUM_MAX);
    scanf("%d", start_number);
    if ((*start_number < START_NUM_MIN) || (*start_number > START_NUM_MAX)){
      puts("NUMBERS NOT IN RANGE");
      exit(1);
    }
  }
    printf("Enter end number from %d to %d: ", END_NUM_MIN, END_NUM_MAX);
    scanf("%d", end_number);
    if ((*end_number < END_NUM_MIN) || (*end_number > END_NUM_MAX)){
      puts("NUMBERS NOT IN RANGE");
      exit(2);
  }
}

void handle_command_line(int argc,char *argv[], int *start_number, int *end_number){
  if (argc == 1){return;}
  if(argc < 3){
      puts("NOT ENOUGH ARGUMENTS");
    return;
  }
    if(strcmp("--start", argv[1]) == 0){
      *start_number = atoi(argv[2]);
    }
}

int main(int argc, char *argv[]) {

  display_start_info(argc);

  if(1 == prompt()){
  }
  else{puts("GOODBYE"); exit(1);}

  // DEMO for a For loop :
  puts("\nfor loop:");
  for (int i = 0; i < argc; i++){
    printf("argv[%d] : %s\n", i, argv[i]);
  }

  //DEMO for a While loop: 
  puts("while loop:");
  int j = 0;
  while (j < argc){
    printf("argv[%d] : %s\n", j, argv[j]);
    j++;
  }

  //DEMO for a Do while loop:
  puts("do while loop:");
  j = 0;
  do{
    printf("argv[%d] : %s\n", j, argv[j]);
    j++;
  }
    while (j < argc);

  printf("\n\n");
  
  int start_number = 0;
  int end_number = 0;

  // HANDLE COMMAND LINE
  handle_command_line(argc,argv, &start_number, &end_number);

  // PROMPT USER INPUT FOR TWO NUMBERS and PRINT THOSE NUMBERS
  if(0 == start_number){
    prompt_for_numbers(&start_number, &end_number);
  }
  else{
    prompt_for_numbers(NULL, &end_number);
  }
  printf("Start Number : %d\n", start_number);
  printf("End Number : %d\n\n", end_number);

  //LOOP DEMOS USING THOSE TWO NUMBERS

  printf("----- LOOP DEMO ------\n");
   printf("for loop: ");
  for(int i = start_number; i <= end_number; i++){
    printf("%d ", i);
  }
  printf("\n");

  j = start_number;
  printf("while loop: ");
  while(j <= end_number){
    printf("%d ", j);
    j++;
  }
  printf("\n");
   printf("do while loop: ");
  j = start_number;
  do{
    printf("%d ", j);
    j++;
  } while (j <= end_number);

  printf("\n");
      
  return 0;

}


```