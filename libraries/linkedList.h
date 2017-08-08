#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef struct node {

    int data;
    struct node* next;
} node;

void addAtBeginning(node** head, int dat);

void addAtLast(node** head, int dat);

void addAtPosition(node** head, int dat, int pos);

void printList(node* ptr);

int deleteAtBegin(node** head);

int deleteAtEnd(node** head);

int deleteAtPos(node** head, int pos);

bool search(node* head, int d);

int count(node* h);