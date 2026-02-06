#include <stdio.h>

int swap(int *first, int *second);

int main(){
    int a = 5, b = 10;

    printf("A = %d\n", a);
    printf("B = %d\n", b);

    swap(&a, &b);

    printf("After swap()\n");
    printf("A = %d\n", a);
    printf("B = %d \n", b);

    return 0;
}

int swap(int *first, int *second){
    *first = *first + *second;
    *second = *first - *second;
    *first = *first - *second;
}
