#include <stdio.h>
#include <assert.h>
#include <sys/time.h>
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(int* arr, int n) {

    for(int i = n - 1; i > 0; i--) {

        for(int j = i - 1; j >= 0; j--) {

            if (arr[i] >= arr[j])
                break;   
            swap(arr, i, j);
        }
    }

}

void testSort(int* arr, int* out, int n) {
    insertionSort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Success\n");
}

void testTime(int n) {

    int arr[n];
    for(int i = n; i > 0; i--) {
        arr[n - i] = i;
    }

    struct timeval start, end;
    gettimeofday(&start, NULL);

    insertionSort(arr, n);

    gettimeofday(&end, NULL);

    long after = end.tv_sec * 1000000L + end.tv_usec;
    long before = start.tv_sec * 1000000L + start.tv_usec;

    printf("Elements: %d, time: %ld\n", n, after - before);
}


int main() {

    //testTime(1600);
    //testTime(3200);
    //testTime(16000);
    //testTime(32000);
    
    int arr[] = {1,- 3, 6, -1, 5};
    int out[] = {-3, -1, 1, 5, 6};
    testSort(arr, out, 5);
}
