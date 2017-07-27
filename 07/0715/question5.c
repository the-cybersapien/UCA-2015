#include <stdio.h>
#include <math.h>

int prime(int n){
	if (n % 2 == 0){
		return 0;
	}
	for(int i = 3; i <= sqrt(n); i+=2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int main(){
	printf("%d\n", prime(43));
	printf("%d\n", prime(9));	
}
