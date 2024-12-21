#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stddef.h>

void* safeMemoryAllocation(size_t size);
void safeMemoryFree(void *ptr);
void demonstrateMemoryManagement();

#endif