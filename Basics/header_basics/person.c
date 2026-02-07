#include <stdio.h>
#include "person.h"
#include <string.h>

void print_person(Person p) {
    printf("Name: %s, Age: %d\n", p.name, p.age);
}

void scan_person(Person *p, const char *name, int age) {
    p->age = age;
    strcpy(p->name, name);
}
