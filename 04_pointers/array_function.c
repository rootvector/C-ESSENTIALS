#include <stdio.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int a[3] = {1, 2, 3};
    printArray(a, 3);
    return 0;
}

