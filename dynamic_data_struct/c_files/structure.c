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