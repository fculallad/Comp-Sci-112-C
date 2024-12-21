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