#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;
void create(Node * head) {
  Node *newnode = (Node*) malloc(sizeof(Node));
  printf("Enter data: ");
  scanf("%d", &newnode->data);
  
}
int main() {
  
}