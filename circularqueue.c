#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 // Define the maximum size of the circular queue

// Circular Queue structure
struct CircularQueue {
    int items[SIZE];
    int front, rear;
};

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return (q->front == (q->rear + 1) % SIZE);
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return (q->front == -1);
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        // Queue becomes empty after this operation
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    printf("Dequeued: %d\n", value);
    return value;
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function to demonstrate circular queue operations
int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 60);
    enqueue(&q, 70);

    display(&q);
    return 0;
}