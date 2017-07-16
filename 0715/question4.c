#include <stdio.h>

int gcd(int m, int n){
	int r;
	while (1){
		r = m % n;
		if (r == 0)
			return n;
		m = n;
		n = r;
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}


int main (){
	printf("%d\n", lcm(15, 4));
}
