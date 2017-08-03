#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int sSwap = 0;
int qSwap = 0;
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

void printArray(int* a, int n) {
    for (int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");

}
int qSort(int* a, int L, int R) {
    int sw = 0;
    if (L >= R)
        return 0;
    int last = L;

    for (int i = L; i <= R; i++) {
        if (a[i] < a[last]) {
            swap(a, ++last, i);
            sw++;
        }
    }
    sw++;
    swap(a, last, L);
    printArray(a, 6);
    sw += qSort(a, L, last - 1);
    sw += qSort(a, last + 1, R);
    return sw;
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
    qSwap = qSort(arr1, 0, n - 1);
    gettimeofday(&end, NULL);
    
    after = end.tv_sec * 1000000L + end.tv_usec;
    before  = start.tv_sec * 1000000L +  start.tv_usec;
    printf("Quick Sort: Elements: %d, time: %ld\n", n, after - before); 

    for(int i = 0; i < n; i++) {
        if(arr[i] != arr1[i]){
            printf("Error %d != %d\n", arr[i], arr1[i]);
        }
    }
}

int main() {

    int arr[] = {3, 5, 1, 2, 9, 5};
    qSort(arr, 0, 6);

    // sSwap = 0;
    // qSwap = 0;
    // testTime(4000);
    // printf("%d Elements qSwaps: %d, sSwaps: %d\n\n\n", 4000, qSwap, sSwap);
    // sSwap = 0;
    // qSwap = 0;
    // testTime(8000);
    // printf("%d Elements qSwaps: %d, sSwaps: %d\n\n\n", 8000, qSwap, sSwap);
    // sSwap = 0;
    // qSwap = 0;
    // testTime(16000);
    // printf("%d Elements qSwaps: %d, sSwaps: %d\n\n\n", 16000, qSwap, sSwap);
}
