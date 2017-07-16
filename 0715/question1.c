#include <stdio.h>

int ways(int n){
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	int x = ways(n - 1) + ways(n - 2);
	return x;
}


int main(){
	printf("%d\n", ways(4));
	printf("%d\n", ways(2));
}
