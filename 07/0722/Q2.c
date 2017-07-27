#include <stdio.h>

int lonelyNumber(int* arr, int n) {
    int num = 0;
    for (int i = 0; i < (sizeof(int) * 8); i++) {
        int sum = 0;
        // Loop through the array
        for (int j = 0; j < n; j++) {
            sum += ((arr[j] >> i) & 1);
        }
        // Get the last bit from sum
        sum = (sum % 3) & 1;
        num ^= (sum << i);
    }
    return num;
}

int main() {

    int arr[] = {1, 2, 2, 2, 1, 3, 1};
    printf("%d\n", lonelyNumber(arr, 7));
    int arr1[] = {222, 445,445, 333,445, 333, 333};
    printf("%d\n", lonelyNumber(arr1, 7));
    return 0;
}
