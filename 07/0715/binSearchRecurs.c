#include <stdio.h>

int binSearch(int* arr, int q, int l, int r){
	if (r < l)
		return -1;
	int mid = (l + r) / 2;
	if (arr[mid] == q)
		return mid;
	if (arr[mid] > q)
		return binSearch(arr, q, l, mid - 1);
	return binSearch(arr, q, mid + 1, r);
}

int main(){

	int arr[] = {2, 3, 5, 6, 9, 10, 33, 58};
	int n = 8;
	printf("result is  %d\n", binSearch(arr, 1, 0, n - 1));
	printf("result is  %d\n", binSearch(arr, 3, 0, n - 1));
	printf("result is  %d\n", binSearch(arr, 100, 0, n - 1));
	printf("result is  %d\n", binSearch(arr, 15, 0, n - 1));
}
