#include <stdio.h>
#include <string.h>

int main() {

    char a[20] = "Hello";
    char b[20] = "World";

    strcat(a, b);      // a = HelloWorld
    printf("%s\n", a);

    printf("Length: %lu\n", strlen(a));

    return 0;
}

