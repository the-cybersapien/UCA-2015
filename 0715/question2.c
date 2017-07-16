#include <stdio.h>

int ways(int n){
	return (n - 1)/2 + 1;
}

int main(){
	printf("%d\n", ways(1));
	printf("%d\n", ways(4));
	printf("%d\n", ways(7));
	printf("%d\n", ways(9));
}
