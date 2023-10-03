#include<stdio.h>
#define MAX 5
typedef struct node {
    int list[MAX];
    int rear;
    int front;
} QUEUE;
void push(QUEUE *queue, int value) {

}
void display( QUEUE *queue) {
    int i;
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->list[i]);
    }
}
int main() {
    QUEUE *queue;
    queue->front = -1;
    queue->front = -1;
    int choice, value;
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);  
        switch (choice) {
        case 1:
            printf("Enter value");
            scanf("%d", &value);
            push(queue, value);
            break;
        case 3:
            printf("Here is the queue: ");
            display(queue);
        default:
            printf("invalid choice");
            break;
        }
    }
    
}