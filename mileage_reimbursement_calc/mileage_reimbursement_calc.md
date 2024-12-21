# Mileage Reimbursement Calc

## main.c


```c

#include <stdio.h>

#define NAME "FORD CULALLAD"
#define DOLLAR_PER_MILE 0.35

int main(void) {
  
  printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
  printf("Code by %s\n", NAME);

  double beg_odometer;
  double end_odometer;
  double miles_driven;

  printf("Enter the beginning odometer reading: ");
  scanf("%lf", &beg_odometer);

  printf("Enter ending odometer reading: ");
  scanf("%lf", &end_odometer);

  miles_driven = (end_odometer) - (beg_odometer);
  printf("You traveled %.1lf miles at $%.2lf per mile.\n", miles_driven, DOLLAR_PER_MILE);

  double reimbursement = (miles_driven) * (DOLLAR_PER_MILE);

  printf("Your reimbursement is $%.2lf", reimbursement);
  
  return 0;
}


```