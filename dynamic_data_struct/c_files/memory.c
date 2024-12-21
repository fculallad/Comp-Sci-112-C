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