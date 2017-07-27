#include <stdio.h>
#include <stdlib.h>

void printArray(int** arr, int m, int n) {
    printf("\n\n");
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void transform(int** arr, int i, int j, int m, int n) {
    for(int a = 0; a < n; a++) {
        arr[i][a] = 0;
    }

    for(int a = 0; a < m; a++) {
        arr[a][j] = 0;
    }
}

void changeZero(int** arr, int m, int n) {

    for (int i = 0; i < m; i++) {
        for(int j = i; j < n; j++) {

            if (!arr[i][j]){
                transform(arr, i, j, m, n);
                break;
            }
        }
    }
}

int** createArr(int m, int n) {
    int** arr = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++){
        arr[i] = (int*)malloc(sizeof(int) * n);
    }
    return arr;
}

int main() {
    int m = 3, n = 3;
    int** arr = createArr(m, n);

    printf("Original Array: \n\n");
    for(int i = 0; i < m; i++) {
        for (int j = 0;j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    changeZero(arr, m, n);

    printf("New Array:");
    printArray(arr, m, n);
}

