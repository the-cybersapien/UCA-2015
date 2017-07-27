#include <stdio.h>

int myWays(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return myWays(n - 1) + myWays(n - 2);
}

int main() {
	printf("%d\n", myWays(200));
}
