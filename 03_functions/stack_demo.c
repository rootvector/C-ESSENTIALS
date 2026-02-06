#include <stdio.h>

void foo(int x) {
    x = x + 5;
    printf("Inside foo: x = %d\n", x);
}

int main() {
    int a = 10;
    foo(a);
    printf("Inside main: a = %d\n", a);
    return 0;
}

