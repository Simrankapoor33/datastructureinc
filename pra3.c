#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure declaration 
typedef struct node {
    char data;
    struct node* link;
} STACK_NODE;

// Prototype declaration
void insertdata(STACK_NODE** PstackTop);
void print(STACK_NODE** PstackTop);
bool push(STACK_NODE** Plist, char dataIn);
bool pop(STACK_NODE** Plist, char* dataOut);

// Function to push data onto the stack
bool push(STACK_NODE** Plist, char dataIn) {
    STACK_NODE* newNode = (STACK_NODE*)malloc(sizeof(STACK_NODE));
    if (!newNode) return false;
    newNode->data = dataIn;
    newNode->link = *Plist;
    *Plist = newNode;
    return true;
}

// Function to pop data from the stack
bool pop(STACK_NODE** Plist, char* dataOut) {
    if (*Plist == NULL) return false;
    STACK_NODE* temp = *Plist;
    *dataOut = temp->data;
    *Plist = temp->link;
    free(temp);
    return true;
}

// Function to insert data into the stack
void insertdata(STACK_NODE** PstackTop) {
    char data;
    printf("Enter data to push onto the stack (enter '.' to stop): ");
    while (true) {
        scanf(" %c", &data);
        if (data == '.') break;
        push(PstackTop, data);
    }
}

// Function to print the stack
void print(STACK_NODE** PstackTop) {
    STACK_NODE* current = *PstackTop;
    printf("Stack contents:\n");
    while (current != NULL) {
        printf("%c\n", current->data);
        current = current->link;
    }
}

int main() {
    STACK_NODE* PstackTop;

    printf("Beginning simple stack program\n\n");
    PstackTop = NULL;
    insertdata(&PstackTop);
    print(&PstackTop);
    printf("\n\nEnd of simple stack program\n");
    return 0;
}