#include <stdio.h>
#include <assert.h>
#include <sys/time.h>

void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void  selectionSort(int* arr, int n) {

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i)
            swap(arr, i, min);
    }
}

void testTime(int* arr,  int n) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    selectionSort(arr, n);

    gettimeofday(&end, NULL);
    long after = end.tv_sec * 1000000L + end.tv_usec;
    long before  = start.tv_sec * 1000000L +  start.tv_usec;
    printf("Elements: %d, time: %ld\n", n, after - before); 
}

int main() {
    int arr1[8000];
    for(int i = 8000; i > 0; i--) {
        arr1[8000-i] = i;
    }
    testTime(arr1, 8000);
    int arr2[16000];
    for(int i = 16000; i > 0; i--) {
        arr2[16000-i] = i;
    }
    testTime(arr2, 16000);
    int arr[32000];
    for(int i = 32000; i > 0; i--) {
        arr[32000-i] = i;
    }
    testTime(arr, 32000);
}

