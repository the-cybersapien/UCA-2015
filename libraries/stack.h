#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int capacity;
    int* arr;
} stack;

stack* createStack(int initSize);

void doubleSize(stack* s);

void decreaseSize(stack* s);

void push(stack* s, int data);

int pop(stack* s);

int peek(stack* s);

void printStack(stack* s);
