#include <stdio.h>
#include "person.h"

int main() {
    Person p;
    scan_person(&p, "Rohan", 18);
    print_person(p);
    return 0;
}
