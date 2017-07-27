#include <stdio.h>
#include <limits.h>
#include <assert.h>

void printBits(int y){
	for (int i = 0; i < 32; ++i) {
		int r = (y >> (31 - i)) & 1;
		printf("%d",r);
	}
	printf("\n");
}

int logicalShift(int a, int x) {

    printBits(a);
    a = a >> x;
    printBits(a);
    a &= (INT_MAX >> (x - 1));
    printBits(a);
    return a;
}

int main() {
    printf("%x\n", INT_MAX);
    printf("%d\n", logicalShift(-1, 1));
    return 0;
}
