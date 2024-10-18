#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue overflow! Cannot enqueue %d\n", item);
        return;
    }
    if (front == -1) {
        front = 0; // Initialize front when first element is added
    }
    rear++;
    queue[rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow! Cannot dequeue from an empty queue\n");
        return -1; // Return a sentinel value for underflow
    }
    int item = queue[front];
    front++;
    return item;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("%d dequeued from queue\n", dequeue());
    display();

    enqueue(40);
    display();

    return 0;
}

