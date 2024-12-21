#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__


typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void initializeStudent(Student *student, const char *name, int age, float gpa);
void printStudentInfo(const Student *student);

#endif