#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("x value: %d\n", x);
    printf("x address: %p\n", &x);
    printf("p value (address): %p\n", p);
    printf("value at p: %d\n", *p);

    return 0;
}
