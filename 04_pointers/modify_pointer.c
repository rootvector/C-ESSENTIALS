#include <stdio.h>

void setPointer(int **p) {
    static int x = 10;
    *p = &x;
}

int main() {
    int *ptr = NULL;
    setPointer(&ptr);
    printf("%d\n", *ptr);
    return 0;
}

