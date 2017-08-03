#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

int mSwap = 0;
int sSwap = 0;
int iSwap = 0;

void swap(int* a, int i, int j) {
    a[i] = a[i] ^ a[j];
    a[j] = a[i] ^ a[j];
    a[i] = a[i] ^ a[j];
}


void  selectionSort(int* arr, int n) {

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i){
            swap(arr, i, min);
            sSwap++;
        }
    }
}

void insertionSort(int* arr, int n) {

    for(int i = n - 1; i > 0; i--) {

        for(int j = i - 1; j >= 0; j--) {

            if (arr[i] >= arr[j])
                break;
            swap(arr, i, j);
            iSwap++;
        }
    }

}

int merge(int* a, int n, int L, int mid, int R) {
	int c = 0;
    int i = L;
    int j = mid + 1;
    int k = 0;
    int* t = malloc((R - L + 1) * sizeof(int));
    while (k <= (R - L)) {
       if (i > mid)
           t[k++] = a[j++];
       else if (j > R)
           t[k++] = a[i++];
       else if (a[i] > a[j]) {
           	t[k++] = a[j++];
           	c += mid - i;
       }
       else
           t[k++] = a[i++];
    }
    for(int i = 0; i < k; i++) {
    	if(a[L + i] != t[i]) {
	        a[L + i] = t[i];
    	}
    }
    return c;
}

int mergeSort(int* a, int n, int L, int R) {
	int c = 0;
    if (L >= R)
        return c;

    int mid = (L + R) / 2;
    c += mergeSort(a, n, L, mid);
    c += mergeSort(a, n, mid + 1, R);
    c += merge(a, n, L, mid, R);
    return c;
}

void testTime(int n) {
    struct timeval start, end;
    int* arr = malloc(n * sizeof(int));

    for(int i = n; i > 0; i--) {
        arr[n-i] = i;
    }
    gettimeofday(&start, NULL);
    selectionSort(arr, n);
    gettimeofday(&end, NULL);
    long after = end.tv_sec * 1000000L + end.tv_usec;
    long before  = start.tv_sec * 1000000L +  start.tv_usec;
    printf("Selection Sort: Elements: %d, time: %ld\n", n, after - before); 

    int* arr1 = malloc(n * sizeof(int));

    for(int i = n; i > 0; i--) {
        arr1[n-i] = i;
    }

    gettimeofday(&start, NULL);
    mSwap = mergeSort(arr1, n, 0, n - 1);
    gettimeofday(&end, NULL);
    
    after = end.tv_sec * 1000000L + end.tv_usec;
    before  = start.tv_sec * 1000000L +  start.tv_usec;
    printf("Merge Sort: Elements: %d, time: %ld\n", n, after - before); 

    int* arr2 = malloc(n * sizeof(int));

    for(int i = n; i > 0; i--) {
        arr2[n-i] = i;
    }

    gettimeofday(&start, NULL);
    insertionSort(arr2, n);
    gettimeofday(&end, NULL);
    
    after = end.tv_sec * 1000000L + end.tv_usec;
    before  = start.tv_sec * 1000000L +  start.tv_usec;
    printf("Insertion Sort: Elements: %d, time: %ld\n", n, after - before); 

    for(int i = 0; i < n; i++) {
        if(arr[i] != arr1[i]){
            printf("Error %d != %d\n", arr[i], arr1[i]);
        }
    }
    printf("Success!\n");
}

int main() {
    mSwap = 0;
    sSwap = 0;
    iSwap = 0;
    testTime(4000);
    printf("%d Elements mSwaps: %d, sSwaps: %d, iSwaps: %d\n\n\n", 4000, mSwap, sSwap, iSwap);
    mSwap = 0;
    sSwap = 0;
    iSwap = 0;
    testTime(8000);
    printf("%d Elements mSwaps: %d, sSwaps: %d, iSwaps: %d\n\n\n", 8000, mSwap, sSwap, iSwap);
    mSwap = 0;
    sSwap = 0;
    iSwap = 0;
    testTime(16000);
    printf("%d Elements mSwaps: %d, sSwaps: %d, iSwaps: %d\n\n\n", 16000, mSwap, sSwap, iSwap);
}
