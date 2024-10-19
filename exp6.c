#include <stdio.h>
#include <stdlib.h>
struct Node {
    int frameData; 
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
void initializeQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}
struct Node* createNode(int frameData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->frameData = frameData;
    newNode->next = NULL;
    return newNode;
}
void enqueue(struct Queue* q, int frameData) {
    struct Node* newNode = createNode(frameData);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Buffered frame: %d\n", frameData);
}
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Buffer is empty. No frame to play.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int frameData = temp->frameData;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return frameData;
}

void playVideo(struct Queue* q) {
    while (!isEmpty(q)) {
        int frame = dequeue(q);
        printf("Playing frame: %d\n", frame);
    }
}
int main() {
    struct Queue buffer;
    initializeQueue(&buffer);
   
    enqueue(&buffer, 1);  
    enqueue(&buffer, 2); 
    enqueue(&buffer, 3);  
    
    playVideo(&buffer);
    
    enqueue(&buffer, 4);  
    enqueue(&buffer, 5); 
    
    playVideo(&buffer);
    
    return 0;
}
