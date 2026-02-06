#include <stdio.h>

int main(){
    int age;
    float height;

    printf("Enter your age: ");         // Output function
    scanf("%d", &age);                  // Input function                 

    printf("Enter your height: ");
    scanf("%f", &height);

    printf("\nYou entered:\n");
    printf("Age = %d\n", age);
    printf("Height = %.2f\n", height);

    return 0;
}
