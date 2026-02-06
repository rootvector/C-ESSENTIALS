#include <stdio.h>

void foo(int *x) {
    *x = *x + 5;
}

int main() {
    int a = 10;
    foo(&a);
    printf("a = %d\n", a);
    return 0;
}

