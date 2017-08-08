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

typedef struct student {
    int rollNo;
    char name[20];
    int age;
} student;

void swapStu(void* a, int i, int j) {
    student** arr = (student**) a;
    student* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int stuCompare(void* arr, int i, int j) {
    student** a = (student**) arr;
    return (a[j]->age > a[i]->age)? -1 : 1;
}

student* createStudent() {
    student* stu = malloc(sizeof(student));
    printf("Enter the roll number and name of student: ");
    scanf("%d %s %d", &(stu->rollNo), stu->name, &(stu->age));
    return stu;
}

void printStu(student** arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d %s %d--", arr[i]->rollNo, arr[i]->name, arr[i]->age);
    }
    printf("\n");
}

int main() {

    student **arr = malloc(sizeof(student*)*3);
    for(int i = 0; i < 3; i++) {
        arr[i] = createStudent();
    }

    quickSort(arr, 0, 2, stuCompare, swapStu);
    printStu(arr, 3);

    return 0;
}
