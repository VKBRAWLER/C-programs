#include<stdio.h>
#include<stdlib.h>
struct node  {
    int data;
    struct node *next;
};
// struct node *insert(struct node *start, int data) {
//     struct node *newNode = (struct node *)malloc(sizeof( struct node));
//     newNode->data = data;
//     newNode->next = NULL;
// }

int main() {
    int i, data;
    struct node *q1 = (struct node *)malloc(sizeof( struct node));
    struct node *q2 = (struct node *)malloc(sizeof( struct node));
    struct node *q3 = (struct node *)malloc(sizeof( struct node));
    struct node *q4 = (struct node *)malloc(sizeof( struct node));
    struct node *q5 = (struct node *)malloc(sizeof( struct node));
    struct node *start = q1;
    q1->data = 21;
    q1->next = q2;
    q2->data = 24;
    q2->next = q3;
    q3->data = 14;
    q3->next = q4;
    q4->data = 86;
    q4->next = q5;
    q5->data = 75;
    q5->next = NULL;
    int count = 0;
    do{
        printf("%d -> ", start->data);
        start = start->next;
        count++;
    } while (count != 40 && start != NULL);
    printf("NULL");
}