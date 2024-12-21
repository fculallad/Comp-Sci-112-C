# C Calculator

## main.c

```c

#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define NAME "Ford Culallad"

int add(int num1,int num2){
   return num1 + num2;
}
int sub(int num1, int num2){
    return num1 - num2;
}
int divide(int num1, int num2){
    return num1/num2;
}
int mult(int num1, int num2){
    return num1*num2;
}
int rem(int num1, int num2){
    return num1 % num2;
}
void startup(int argc){
    printf("Argument Count : %d\n", argc);
    puts("CALCULATOR PROGRAM v3"); 
    printf("Made by %s\n", NAME);  

    time_t startTime;
    startTime = time(NULL);  
    printf("%ld\n", startTime);
    char *start_time;
    start_time = ctime(&startTime); // Converts too a string

    printf("Start Time : %s", start_time);
}

int main(int argc, char *argv[]) {

    /* Calculator Program v1 w/ hard-coded values
     int num1 = 5 
     int num2 = 4 
        */
    
    startup(argc);
    int num1, num2, result; //V2 - Declaring variables that will store user input from console
    char op;

    if (1 == argc){
    puts("Enter the first number: ");
    scanf("%d", &num1);

    puts("Enter the operation(+,-,*,/,%): ");
    scanf(" %c", &op);

    puts("Enter the second number: ");
    scanf("%d", &num2);
    }
    else{
        printf("argv[0]: %s\n", argv[0]);
        printf("argv[1] : %s\n", argv[1]);
        printf("argv[2] : %s\n", argv[2]);
        printf("argv[3] : %s\n", argv[3]);
        
        num1 = atoi(argv[1]);
        op = argv [2] [0];
        num2 = atoi(argv[3]);
    }

    if ('+' == op){ 
        result = add(num1,num2);
        printf("OK %d %c %d\n", num1,op,num2);
        printf("Sum: %d\n", result);
    }
    if ('-' == op){
        result = sub(num1,num2);
        printf("OK %d %c %d\n", num1,op,num2);
        printf("Subtraction : %d\n", result);
    }
    if('*' == op){
        result = mult(num1,num2);
        printf("OK %d %c %d\n", num1,op,num2);
        printf("Multiplication : %d\n", result);
    }
    if ('/' == op){
        result = divide(num1,num2);
        printf("OK %d %c %d\n", num1,op,num2);
        printf("Division : %d\n", result);
    }
    if ('%' == op){
        result = rem(num1,num2);
        printf("OK %d %c %d\n", num1,op,num2);
        printf("Remainder: %d\n", result);

    }            

    printf("ALL DONE !");

  return 0;

}   


```