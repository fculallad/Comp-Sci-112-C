# Payroll Program

# employee.h

```c

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    char firstName[32];
    char lastName[32];
    char gender;  // M for male, F for female, T for Third Gender
    int tenure;
    char rate;    // H for hourly, W for weekly
    double salary;
} employee_t;

#endif

```

## main.c

```c

#include <stdio.h>
#include "payroll.h"
#include "employee.h"
#include "fileio.h"
#include "displayInfo.h"

#define PAYROLL_FILE "payroll.txt"

int main(void) {

  displayInfo();
  printf("\n");
  
  

    if (payroll_init() != 0) {
        printf("Error initializing payroll system\n");
        return -1;
    }
    if (fileio_init(PAYROLL_FILE) != 0) {
        printf("Error opening payroll file\n");
        return -1;
    }

    employee_t emp;
    while (fileio_get_employee(&emp) == 0) {
        payroll_add(&emp);
    }

    printf("*****************************");
    printf("\nEmployee List (First to Last):\n");
    printf("*****************************");
    printf("\n\n");
    payroll_print_first_to_last();

    printf("\n");
    printf("*****************************");
    printf("\nEmployee List (Last to First):\n");
    printf("*****************************");
    printf("\n\n");
    payroll_print_last_to_first();

    printf("\nStatistics:\n");
    printf("Total Employees: %d\n", payroll_get_num_employees());
    printf("Male Employees: %d\n", payroll_get_num_employees_by_gender('M'));
    printf("Female Employees: %d\n", payroll_get_num_employees_by_gender('F'));
    printf("Third Gender Employees: %d\n", payroll_get_num_employees_by_gender('T'));

    return 0;
}

```

## displayInfo.c

```c

#include <stdio.h>
#include <time.h>
#define VERSION "1.0.0"
#define NAME "FORD CULALLAD"

void displayInfo(){

puts("C-Based Payroll Processing Program");
printf("VERSION : %s", VERSION);
printf("Copyright (c) %s\n", NAME);

  time_t now = time(NULL);
  char *nowStr = ctime(&now);
  printf("%s", nowStr);

}

```

## fileio.c

```c

#include <stdio.h>
#include "fileio.h"

static FILE *file = NULL;

int fileio_init(const char *filename) {
    file = fopen(filename, "r");
    return (file == NULL) ? -1 : 0;
}

int fileio_get_employee(employee_t *employee) {
    if (file == NULL) return -1;

    int result = fscanf(file, "%s %s %c %d %c %lf",
                       employee->firstName,
                       employee->lastName,
                       &employee->gender,
                       &employee->tenure,
                       &employee->rate,
                       &employee->salary);
    
    return (result == 6) ? 0 : -1;
}

```

## payroll.c

```c

#include <stdio.h>
#include "payroll.h"

static int num_employees = 0;
static employee_t employees[40];

int payroll_init(void) {
    num_employees = 0;
    return 0;
}

int payroll_add(employee_t *employee) {
    if (num_employees >= MAX_NUM_EMPLOYEES) {
        return -1;
    }
    employees[num_employees++] = *employee;
    return 0;
}

int payroll_get_num_employees(void) {
    return num_employees;
}

int payroll_get_num_employees_by_gender(char c) {
    int count = 0;
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].gender == c) {
            count++;
        }
    }
    return count;
}

void payroll_print_first_to_last(void) {
    for (int i = 0; i < num_employees; i++) {
        printf("%s %s (%c) - Tenure: %d, Rate: %c, Salary: %.2f\n",
               employees[i].firstName,
               employees[i].lastName,
               employees[i].gender,
               employees[i].tenure,
               employees[i].rate,
               employees[i].salary);
    }
}

void payroll_print_last_to_first(void) {
    for (int i = num_employees - 1; i >= 0; i--) {
        printf("%s %s (%c) - Tenure: %d, Rate: %c, Salary: %.2f\n",
               employees[i].firstName,
               employees[i].lastName,
               employees[i].gender,
               employees[i].tenure,
               employees[i].rate,
               employees[i].salary);
    }
}



```

## payroll.txt

```c

Howard     Starr           M 8 H   30.00
Joan       Jacobus         F 9 W  925.00
Davidi      Renn            T 3 H    14.75
Albert     Cahana          M 3 H   18.75
Douglas    Sheer           M 5 W  250.00
Shari      Buchman         F 9 W  325.00
Freda      Heller          F 1 H    17.50
Ricky      Mofsen          M 6 H   12.50
Jean       Brennan         T 6 H    15.40
Deborah    Starr           F 3 W 1000.00
Jamie      Michaels        F 8 W  150.00

```