#include <stdio.h>

// function declaration (prototype)
int add(int a, int b);

int main() {

    int result = add(3, 4);
    printf("Result = %d\n", result);

    return 0;
}

// function definition
int add(int a, int b) {
    return a + b;
}

