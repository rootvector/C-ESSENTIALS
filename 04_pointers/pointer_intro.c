#include <stdio.h>

int main() {

    int a = 10;
    int *p = &a;

    printf("a = %d\n", a);
    printf("&a = %p\n", &a);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);
    int arr[3] = {10, 20, 30};
    int *ptr = arr;

    printf("%d\n", *ptr);      // 10
    printf("%d\n", *(ptr+1));  // 20
    printf("%d\n", *(ptr+2));  // 30

    return 0;
}

