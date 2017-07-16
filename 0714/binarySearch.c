#include <stdio.h>

int binSearch(int* arr, int n, int query){

	int i = 0;
	int j = n - 1;

	while(i <= j){
		int center = (i + j) / 2;
		printf("%d %d %d\n", i, j, center);
		if (arr[center] > query) {
			j = center - 1;
		} else if (arr[center] < query) {
			i = center + 1;
		} else {
			return center;
		}
	}
	return -1;
}

int main() {

	int arr[] = {2, 3, 4, 6, 8, 9, 10, 16};
	int num = 8;

	int pos = binSearch(arr, num, 15);
	printf("%d\n", pos);
	pos = binSearch(arr, num, 9);
	printf("%d\n", pos);
	pos = binSearch(arr, num, 2);
	printf("%d\n", pos);
	pos = binSearch(arr, num, 5);
	printf("%d\n", pos);
	pos = binSearch(arr, num, 0);
	printf("%d\n", pos);
	return 0;
}
