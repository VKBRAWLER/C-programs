#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;
Node * createNewNode () {
  Node *newnode = (Node*) malloc(sizeof(Node));
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->data = 0;
  return newnode;
}
void insert (Node* head, int x) {
  Node *newnode = createNewNode();
  newnode->data = x;
  if (head == NULL) {
    head = newnode; 
  }
  else if (head->data > x) {
    if (head->left == NULL) {
      head->left = newnode;
      return;
    }
    insert(head->left, x);
  }
  else {
    if (head->right == NULL) {
      head->right = newnode;
      return;
    }
    insert(head->right, x);
  }
}
void Display (Node *head) {
  if (head != NULL) {
    Display(head->left);
    printf("%d ", head->data);
    Display(head->right);
  }
}
int main() {
  int x;
  Node * root = createNewNode();
  while (1) {
    printf("Enter data (-1 if end): ");
    scanf("%d", &x);
    if (x == -1) break;
    insert(root, x);
  }
  Display(root);
}