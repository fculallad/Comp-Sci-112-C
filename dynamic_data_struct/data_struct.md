# Dynamic Data Struct

Lesson 13

```cpp

#include <stdio.h>
#include "displayInfo.h"
#include "array.h"
#include "pointers.h"
#include "structure.h"
#include "memory.h"

int main() {

    displayInfo();
  
    // Array Demo
    printf("--- Arrays Demonstration ---\n");
    int myArray[MAX_ARRAY_SIZE];
    initializeArray(myArray, MAX_ARRAY_SIZE);
    printArray(myArray, MAX_ARRAY_SIZE);
    printf("Sum of array: %d\n\n", sumArray(myArray, MAX_ARRAY_SIZE));

    // Pointers Demo
    printf("--- Pointers Demonstration ---\n");
    demonstratePointers();

    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swapValues(&a, &b);
    printf("After swap: a = %d, b = %d\n\n", a, b);

    // Structures Demo
    printf("--- Structures Demonstration ---\n");
    Student student;
    initializeStudent(&student, "John Doe", 20, 3.75);
    printStudentInfo(&student);
    printf("\n");

    // Memory Management
    printf("--- Memory Management Demonstration ---\n");
    demonstrateMemoryManagement();

    return 0;
}

```
#include <stdio.h>
#include "array.h"

void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }
}

void printArray(int arr[], int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumArray(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}


```cpp

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string reverseString (string str){

    //Using a Loop
    string reverse{};
    
    for(int i = *str.end(); i >= 0; i--){
        reverse += str[i];
    }
    return reverse;

    //Using std::string()
    return string(str.rbegin(), str.rend());

    //Using std::reverse()
    reverse(str.begin(), str.end());
    return str;
}

```

```cpp

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


```

```cpp

#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

void* safeMemoryAllocation(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    return ptr;
}

void safeMemoryFree(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
    }
}

void demonstrateMemoryManagement() {
  
    int *dynamicInt = (int*)safeMemoryAllocation(sizeof(int));
    *dynamicInt = 42;

    printf("Dynamically allocated integer: %d\n", *dynamicInt);

  
    safeMemoryFree(dynamicInt);
}

```

```cpp

#include <stdio.h>
#include <stdlib.h>
#include "pointers.h"

void demonstratePointers() {
    int x = 10;
    int *ptr = &x;  

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Pointer value: %p\n", (void*)ptr);
    printf("Value through pointer: %d\n", *ptr);
}

void swapValues(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* createDynamicArray(int size) {
    return (int*)malloc(size * sizeof(int));
}

void freeDynamicArray(int *arr) {
    free(arr);
}

```

```cpp

#include <stdio.h>
#include <string.h>
#include "structure.h"

void initializeStudent(Student *student, const char *name, int age, float gpa) {
    strncpy(student->name, name, sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0';  
    student->age = age;
    student->gpa = gpa;
}

void printStudentInfo(const Student *student) {
    printf("Student Information:\n");
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %.2f\n", student->gpa);
}



```
