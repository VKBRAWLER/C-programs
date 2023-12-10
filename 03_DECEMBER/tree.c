#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;
Node* create() {
  int x;
  Node *newnode = (Node*) malloc(sizeof(Node));
  printf("Enter data (-1 if end): ");
  scanf("%d", &x);
  if (x == -1) return NULL;
  newnode->data = x;
  printf("Enter left node of %d: \n", x);
  newnode->left = create();
  printf("Enter right node of %d: \n", x);
  newnode->right = create();
  return newnode;
}
void Display (Node *head) {
  if (head != NULL) {
    Display(head->left);
    printf("%d ", head->data);
    Display(head->right);
  }
}
int main() {
  Node * head;
  head = create();
  Display(head);
}