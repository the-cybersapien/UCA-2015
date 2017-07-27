#include <stdio.h>

void swap(int* a, int* b) {
    *x = *x ^ (*y);
    *y = *x ^ (*y);
    *x = *x ^ (*y);
}

int main() {
    int x = 5, y = 6;

    printf("x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("x = %d, y = %d\n", x, y);

    return 0;
}
