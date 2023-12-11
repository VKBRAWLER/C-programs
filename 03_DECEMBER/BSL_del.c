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
Node *insert (Node* head, int x) {
  Node *newnode = createNewNode();
  newnode->data = x;
  if (head == NULL) return newnode;
  if (head->data > x) {
    if (head->left == NULL) { head->left = newnode; }
    else { head->left = insert(head->left, x); }
  }
  else if (head->data <= x) {
    if (head->right == NULL) { head->right = newnode; }
    else { head->right = insert(head->right, x); }
  }
  return head;
}
Node *Find(Node* head, int x, char* p) {
  if (head != NULL) {
    if (head->data == x) { *p = 's'; return NULL;}
    else if (head->data > x) {
      if (head->left) {
        if (head->left->data == x) { *p = 'l'; return head; }
        else { Find(head->left, x, p); }
      }
    }
    else if (head->data <= x) { 
      if (head->right) {
        if (head->right->data == x) { *p = 'r'; return head; }
        else { Find(head->right, x, p); }
      }
     }
  }
}
void Delete (Node* head, int x) {
  Node *xParent = createNewNode();
  char p = '\0';
  xParent = Find(head, x, &p);
  if (!p) { printf("element not found"); return; }
  Node *xNode = (p=='l')? xParent->left: xParent->right;
  if (xNode->left && xNode->right) { printf("Not possible"); return; }
  else {
    if (p == 'l') { 
      (xNode->left) ? (xParent->left = xNode->left) : (xParent->left = xNode->right);
     }
    if (p == 'r') { 
      (xNode->left) ? (xParent->right = xNode->left) : (xParent->right = xNode->right);
     }
  }}
void Display (Node *head) {
  if (head != NULL) {
    Display(head->left);
    printf("%d ", head->data);
    Display(head->right);
  }
}
int main() {
  int x;
  Node * root = NULL;
  // while (1) {
  //   printf("Enter data (-1 if end): ");
  //   scanf("%d", &x);
  //   if (x == -1) break;
  //   root = insert(root, x);
  // }
  int i = 0;
  int arr[] = {5,3,4,1,2,0,7,8,6,9,-1};
  while (1) {
    x = arr[i++];
    if (x == -1) break;
    root = insert(root, x);
  }
  Delete(root, 0);
  printf("\n");
  Display(root);
}

