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