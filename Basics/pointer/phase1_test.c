#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void fill_person(Person *p, const char *name, int age) {
    strcpy(p->name, name);
    p->age = age;
}

int main() {
    Person *p = malloc(sizeof(Person));

    fill_person(p, "rootvector", 19);
    printf("Name: %s | Age: %d\n", p->name, p->age);

    free(p);
    return 0;
}
