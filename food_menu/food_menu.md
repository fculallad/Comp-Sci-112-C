# Food Menu Program

## main.c

```c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int num_apples = 0;
int num_burgers = 0;
int num_corn = 0;
int num_drinks = 0;
int num_extras = 0;
int num_fries = 0;


#define VERSION 5
#define NAME "FORD CULALLAD"

void introduction(){
  puts("FOOD MENU PROGRAM");
  printf("VERSION : %d\n", VERSION);
  printf("Code by: %s\n", NAME);
}
void displayWelcome(){
  puts("Welcome to our new online ordering system!\n");
}
void askAboutSpecials(){
  puts("Do you want to see today's specials? (y/n)");
  int inputOne = getchar();
  getchar();

  if ('y' == inputOne || 'Y' == inputOne){
    printf("Today's Specials : ...\n");
  }

}
int takeoutDelivery(){
  printf("Would this order be takeout or delivery (t/d)?\n");
  int preference = getchar();
  getchar(); //eat enter key

  //RETURN 1 : TAKEOUT || RETURN 2 : DELIVERY  || RETURN -1 : USER INPUT ERROR
  if(preference == 't' || preference == 'T'){
    return 1; 
  }
  else if(preference == 'd' || preference == 'D'){
    return 0;
  }

  else{
    return -1;
  }
}
void display_menu(){
  puts("MENU OPTIONS:");
  puts("a)Apples, b)Burgers, c)Corn, "
    "d)Drink, e)Extra, f)Fries, q)QUIT");
}
void take_the_order(){
  int taking_order = 1;
  while (1 == taking_order){
    display_menu();
    int choice = getchar();
    getchar();
    switch(choice){
      case 'a':
        num_apples++;
        break;
      case 'b':
        num_burgers++;
        break;
      case 'c':
        num_corn++;
        break;
      case'd':
        num_drinks++;
        break;
      case 'e':
        num_extras++;
        break;
      case 'f':
        num_fries++;
      break;
      case 'q': return;
      default: puts("Please enter a menu choice");
    }
  }
  /*
  int num_apples = 0;
  int num_burgers = 0;
  int num_corn = 0;
  int num_drinks = 0;
  int num_extras = 0;
  int num_fries = 0;
    */
}
void payment_method(){
  puts("SELECT YOUR PAYMENT METHOD: ");
  puts("1)CASH 2)CREDIT 3)CRYPTO");
  int payment = getchar();
  getchar();

  switch(payment){
    case '1':
      puts("SEE CASHIER FOR CASH PAYMENT");
      break;
    case '2':
      puts("PROCESSING. . .");
      sleep(2);
      puts ("YOUR PAYMENT HAS BEEN ACCEPTED");
      break;
    case '3':
      puts("PROCESSING. . .");
      sleep(2);
      puts ("YOUR PAYMENT HAS BEEN ACCEPTED");
      break;
    default: puts("PAYMENT DECLINED. PLEASE TRY AGAIN");
  }
}
void order_summary(){

  puts("ORDER SUMMARY: ");
  if (0 != num_apples){
    printf("Apples: %d\n", num_apples);
  }
  if (0 != num_burgers){
    printf("Burgers: %d\n", num_burgers);
  }
  if (0 != num_corn){
    printf("Corn: %d\n", num_corn);
  }
  if(0 != num_fries){
    printf("Fries: %d\n", num_fries);
  }
  if(0 != num_drinks){
    printf("Drinks: %d\n", num_drinks);
  }
  if(0 != num_extras){
    printf("Extras: %d\n", num_extras);
  }
}
void receipt(time_t now, int total, int result){
  char *now_str = ctime(&now);
  char store_name[] = "Fords Restaurant";
  char cashier[] = "FORD CULALLAD";
  int tax = 0;

  printf("*******************************\n");
  printf("*    %s         *\n", store_name);
  printf("*******************************\n\n");
  if(1 == result){
    puts("*TAKEOUT*");
  }
  else if(0 == result){
    puts("*DELIVERY*");
  }
  printf("%s", now_str);
  printf("Cashier: %s\n", NAME);
  printf("\n");

  //Columns
  printf("%-20s %5s %10s\n", "Item", "Qty", "Price");
  printf("-------------------------------------\n");

  //Itemized Summary
  printf("%-20s %5d %10i\n", "Apples", num_apples, 1);
  printf("%-20s %5d %10i\n", "Burgers", num_burgers, 1);
  printf("%-20s %5d %10i\n", "Corn", num_corn, 1);
  printf("%-20s %5d %10i\n", "Drink", num_drinks, 1);
  printf("%-20s %5d %10i\n", "Extra", num_extras, 1);
  printf("%-20s %5d %10i\n", "Fries", num_fries, 1);
  printf("-------------------------------------\n");

  //Price
  printf("%-20s %5s %10i\n", "Subtotal", "", total);
  printf("%-20s %5s %10i\n", "Tax (0%)", "", tax);
  printf("%-20s %5s %10i\n", "Total", "", total);
  printf("-------------------------------------\n");
  
  
}

int main (void){

  int result;
  
  introduction();
  displayWelcome();
  askAboutSpecials();
  result = takeoutDelivery();
  take_the_order();
  
  int total = num_apples + num_burgers + num_corn + num_drinks + num_extras + num_fries;
  time_t now = time(NULL);
  
  puts("\nGENERATING A RECEIPT. . . ");
  sleep(2);
  printf("\n");
  printf("\n");
  receipt(now,total,result);
  
  printf("\nYOUR TOTAL IS : $%d\n", total);
  payment_method();
  
  return 0;
}

```

## txt

```
Hello
The integer value is: 6

Hello std.out

```

```
Hello to stderr

```