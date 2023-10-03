#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct node {
    int list[MAX];
    int rear;
    int front;
} QUEUE;
void push(QUEUE *queue, int value) {
    if (queue->front == queue->rear) { queue->front = 0; queue->rear = 0;}
    if (queue->rear == MAX) { printf("Queue is full\n"); return;}
    queue->list[queue->rear] = value;
    queue->rear = (queue->rear) + 1;
}
void pop(QUEUE *queue) {
    if (queue->front == queue->rear) { printf("Queue is empty\n"); return;}
    printf("Element poped: %d\n", queue->list[queue->front]);
    queue->front = (queue->front) + 1;
}
void display( QUEUE *queue) {
    if (queue->front == queue->rear) { printf("Queue is empty\n"); return;}
    printf("Here is the queue: ");
    int i;
    for (i = queue->front; i < queue->rear; i++) {
        printf("%d ", queue->list[i]);
    }
    printf("\n");
}
int main() {
    QUEUE *queue = (QUEUE*) malloc(sizeof(QUEUE));
    queue->front = -1;
    queue->rear = -1;
    int choice, value;
    printf("front: %d, rear: %d\n", queue->front, queue->rear);
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);  
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(queue, value);
            break;
        case 2:
            pop(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
    
}