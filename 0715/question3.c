#include <stdio.h>
#include <math.h>

int cube(int x){
	return x * x * x;
}
int isArmstrong(int n){
	int num = n;
	int sum = 0;
	while (num != 0){
		sum += cube(num % 10);
		num /= 10;
	}
	if (sum==n)
		return 1;
	return 0;
}


int main(){
	printf("%d\n", isArmstrong(371));
	printf("%d\n", isArmstrong(44));
}
