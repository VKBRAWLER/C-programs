#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} NODE;
NODE* head = NULL;
void insertion(int v) {
    NODE* new_node = (NODE*)malloc(sizeof(NODE));
    new_node->data = v;
    new_node->next = NULL;
    NODE* ptr = head;
    if (head == NULL){ 
        head = new_node;
        new_node->prev == NULL;
        }
    else {
        for (int i=0; ptr->next !=NULL;i++){
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}
void display() {
    NODE* ptr = head;
    for (int i=0; ptr != NULL;i++){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void rev() {
    NODE* ptr = head;
    if (head == NULL) { printf("Empty\n");}
    while (ptr->next != NULL)
    {
       ptr = ptr->next;
    }
    
    for (int i=0; ptr != NULL; i++){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}
int main() {
    int n,v;
    // printf("Enter the lenght of the linklist: ");
    // scanf("%d", &n);
    printf("Enter the value:\n");
    for (int i=0;i<MAX;i++){
        scanf("%d", &v);
        insertion(v);
    }
    display();
    rev();
}