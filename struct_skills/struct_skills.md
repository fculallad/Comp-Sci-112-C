# Structure Skills

## main.c

```c

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct{

  char name[MAX_NAME_LENGTH];
  int id;
  double gpa;

} student_t;

void printfStudent(student_t student){
  printf("%s\n%d\n%f\n", student.name, student.id, student.gpa);
  student.gpa = 200.1; // WILL NOT REASSIGN VALUE TO 200.1
}


void init_student(student_t *p, char *name, int id, double gpa){

  strcpy(p->name, name);
  p->id = id;
  p->gpa = gpa;
}

typedef struct{

  char *name;
  int hexVal;

}colors_t;

colors_t colors[] = {

{"Red", 0xff0000},
{"Green", 0x00ff00},
{"Blue", 0x0000ff}

};


int main(void) {

  printf("C Struct Skills\n");
  printf("\n");

  for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++){
    printf("%s  -  0x%08x\n", colors[i].name, colors[i].hexVal);
  }

  printf("\n");
  colors_t *pc = &colors[0];
  for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++){
    printf("%s  -  0x%08x\n", pc->name, pc->hexVal);
    pc++;
  }
  
  //int count;
  //int number;

  student_t john;
  student_t sally;

  /*student_t john = { "John Doe", 35121, 4.0 };
    printf("Name: %s\n", john.name);
    printf("ID: %d\n", john.id);
    printf("GPA: %.1f\n", john.gpa);
*/

  init_student(&john, "John Doe", 123, 4.0);
  
  printf("\n\n");


 printfStudent(john);
 printfStudent(john);

  printf("\n\n");

/*  student_t sally = {"Sally Doe", 54321, 3.6};
    printf("Name: %s\n", sally.name);
    printf("ID: %d\n", sally.id);
    printf("GPA: %.1f\n", sally.gpa);
  */

  init_student(&sally, "Sally Doe", 456, 2.3);
  
  printfStudent(sally);
  printfStudent(sally);

  return 0;
}

```