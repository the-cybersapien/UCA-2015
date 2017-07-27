#include <stdio.h>
#include <limits.h>

void printBits(int y) { 

    for( int i = 0; i < 32; i++) {
        int r = (y >> (31 - i)) & 1;
        printf("%d", r);
    }
    printf("\n");
}

int flipBits(int x, int p, int n) {

    int flip = ~(-1 << n);
    printBits(flip);
    flip <<= 31 - p;
    printBits(flip);

    return x ^ flip;
}

int main() {

    printf("%d\n", flipBits(25, 28, 3));

    return 0;
}
