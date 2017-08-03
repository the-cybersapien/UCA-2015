#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef struct node {

    int data;
    struct node* next;
} node;

void addAtBeginning(node** head, int dat) {

    node* newNode =(node*)malloc(sizeof(node));
    newNode->data = dat;
    newNode->next = *head;
    *head = newNode;
}

void addAtLast(node** head, int dat) {

    if (*head == NULL) {
        addAtBeginning(head, dat);
        return;
    }

    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = dat;
    newNode->next = NULL;

    node* ptr = *head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}

void addAtPosition(node** head, int dat, int pos) {

    if (pos == 0) {
        addAtBeginning(head, dat);
        return;
    }
    int i = 0;
    node* current = *head;
    while ((i < (pos - 1)) && current != NULL) {
        current = current->next;
        i++;
    }

    if(current != NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = dat;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void printList(node* ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int deleteAtBegin(node** head) {
    if( *head != NULL) {

        int data = (*head)->data;
        node* c = *head;
        *head = (*head)->next;
        free(c);
        return data;
    }
    printf("Error! List is empty\n");
    return -1;
}

int deleteAtEnd(node** head) {

    if (*head == NULL || (*head)->next == NULL) {
        return deleteAtBegin(head);
    }
    node* current = *head;
    while(current->next->next) {
        current = current->next;
    }
    node* tmp = current->next;
    int x = tmp->data;
    current->next = NULL;
    free(tmp);
    return x;
}

int deleteAtPos(node** head, int pos) {
    if(pos == 0 || *head == NULL){
        return deleteAtBegin(head);
    }
    int i = 0;
    node* current = *head;
    while(i < pos - 1 && (current)->next) {
        i++;
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Error! position not available!\n");
        return -1;
    }
    node* tmp = current->next;
    int dat = tmp->data;
    current->next = tmp->next;
    return dat;
}

bool search(node* head, int d) {
    while(head != NULL) {
        if (head->data == d) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int count(node* h) {

    if (h == NULL)
        return 0;
    return count(h->next) + 1;
}

void reverseList(node** head) {
    node *current = *head;
    node *next = NULL;
    node *prev = NULL;
    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

node* reverseListRec(node *head) {
    node* first = head;
    node* second = first->next;
    if (second == NULL)
        return first;
    node* h = reverseListRec(second);
    second->next = first;
    first->next = NULL;
    return h;
}

void reversePair(node **head) {

    node* first = *head;
    node* second;
    second = first->next;
    node** current = head;

    while(first != NULL && second != NULL) {

        first->next = second->next;
        second->next = first;
        *current = second;
        current = &(first->next);
        first = first->next;
        // Add a null safety check
        if (first)
            second = first->next;
    }
}

int main() {

    node* x = NULL;
    deleteAtBegin(&x);
    addAtBeginning(&x, 20);
    printList(x);
    addAtBeginning(&x, 440);
    printList(x);
    addAtBeginning(&x, 210);
    printList(x);
    addAtBeginning(&x, 130);
    printList(x);
    addAtLast(&x, 22);
    printList(x);
    addAtPosition(&x, 2, 10);
    printList(x);
    addAtPosition(&x, 2, 5);
    printList(x);
    addAtPosition(&x, 2, 3);
    printList(x);
    printf("Deleted: %d\n", deleteAtBegin(&x));
    printList(x);
    deleteAtEnd(&x);
    printList(x);
    deleteAtPos(&x, 2);
    printList(x);
    assert(search(x, 20) == true);
    assert(search(x, 30) == false);
    printf("%d\n", count(x));
    reverseList(&x);
    printList(x);
    x = reverseListRec(x);
    printList(x);

    reversePair(&x);
    printList(x);

    return 0;
}
