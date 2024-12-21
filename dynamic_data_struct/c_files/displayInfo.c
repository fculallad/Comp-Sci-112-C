#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VERSION "1.0.0"
#define NAME "Ford Culallad"
void displayInfo(){

  printf("*****************************\n");
  printf("Dynamic Data Structures Demo\n");
  printf("Version: %s\n", VERSION);
  printf("Copyright (c) %s\n", NAME);

  time_t now = time(NULL);
  char *time_now = ctime(&now);
  printf("%s", time_now);
  printf("*****************************\n\n");

  
}