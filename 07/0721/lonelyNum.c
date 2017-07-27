#include <stdio.h>
#include <assert.h>

int findLonely(int* arr, int n) {

    int x = 0;

    for (int i = 0; i < n; i++) {
        x ^= arr[i];
    }

    return x;
}

int main() {

    int arr[] = {1, 2, 3, 1, 3};
    assert(findLonely(arr, 5) == 2);

    int arr1[] = {1, 1, 2, 3, 4, 5, 5, 6, 4, 3, 2};
    printf("%d\n", findLonely(arr1, 11));

    return 0;
}

