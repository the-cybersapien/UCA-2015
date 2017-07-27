#include <stdio.h>

void printBits(int y){
	for (int i = 0; i < 32; ++i) {
		int r = (y >> (31 - i)) & 1;
		printf("%d",r);
	}
	printf("\n");
}

int main() {

	int x = 0xFFFFFFFF;

	printBits(x);
	printBits(x >> 5);
	printBits(22);
	printBits(45);
	printBits(2);
	printBits(1);
	printBits(4);
	printBits(44);
}
