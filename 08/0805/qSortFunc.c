#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void quickSort(void *arr, int L, int R, int (*comp)(void *, int i, int j), void (*swap)(void* ptr, int i, int j)) {
    if (L >= R)
        return;
    int last = L;
    for (int i = L; i <= R; ++i) {
        if (comp(arr, i, last) < 0) {
            swap(arr, i, last);
        }
    }
    swap(arr, last, L);
    quickSort(arr, L, last - 1, comp, swap);
    quickSort(arr, last + 1, R, comp, swap);
}

int stringCompare(void *a, int i, int j) {
    char** arr = (char**) a;
    return strcmp(arr[i], arr[j]);
}

void stringSwap(void* a, int i, int j) {
    char** arr = (char**) a;
    char* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void print(char *a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%s ", a[i]);
    }
    printf("\n");
}

typedef struct student {
    int i;
    char name[20];
} student;

student* createStudent() {
    student* stu = malloc(sizeof(student));
    printf("Enter the roll number and name of student: ");
    scanf("%d %s", &(stu->i), stu->name);
    return stu;
}

void printStu(student** arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d %s ", arr[i]->i, arr[i]->name);
    }
    printf("\n");
}

void swapStu(void* a, int i, int j) {
    student** arr = (student**) a;
    student* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int stuCompare(void* arr, int i, int j) {
    student** a = (student**) arr;
    return (a[j]->i > a[i]->i)? -1 : 1;
}

int main() {
    char *a[] = {"Hello", "How", "Are", "You"};
    print(a, 4);
    quickSort(a, 0, 3, stringCompare, stringSwap);
    print(a, 4);

    student **arr = malloc(sizeof(student*)*3);
    for(int i = 0; i < 3; i++) {
        arr[i] = createStudent();
    }

    quickSort(arr, 0, 2, stuCompare, swapStu);
    printStu(arr, 3);
}
