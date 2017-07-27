#include <stdio.h>

void printBits(int y) { 

    for( int i = 0; i < 32; i++) {
        int r = (y >> (31 - i)) & 1;
        printf("%d", r);
    }
    printf("\n");
}

int isPowerOfTwo(int x) {
    	x &= (x - 1);
    		
    return bitCount == 1 ? 1 : 0;
}

int main() {
    printf("%d\n", isPowerOfTwo(22));
    printf("%d\n", isPowerOfTwo(8));
    printf("%d\n", isPowerOfTwo(3));
    printf("%d\n", isPowerOfTwo(339));
    printf("%d\n", isPowerOfTwo(3211));
    
}
