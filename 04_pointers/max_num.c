#include <stdio.h>

void mymax(int *, int *);

int main(){
    int a = 30, b = 12;

    mymax(&a, &b);

    return 0;
}

void mymax(int *first, int *second){
    if(*first > *second)
        printf("Max is: %d", *first);
    else
        printf("Max is: %d", *second);
}

