#include <stdio.h>
#include <limits.h>

void printBits(int y){
	for (int i = 0; i < 32; ++i) {
		int r = (y >> (31 - i)) & 1;
		printf("%d",r);
	}
	printf("\n");
}

int checkSign(int x) {
    return (x >> 31) | ! (!x);
}

int main() {
    printBits(!!0);
    printf("%d-> %d\n",1, checkSign(1));
    printf("%d -> %d\n", -5, checkSign(-5));

}
