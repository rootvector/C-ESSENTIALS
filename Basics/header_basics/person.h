#ifndef PERSON_H
#define PERSON_H

typedef struct {
    char name[50];
    int age;
}  Person;

void print_person(Person p);
void scan_person(Person *p, const char *name, int age);

#endif
