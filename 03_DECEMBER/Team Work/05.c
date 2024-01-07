// Write a C program to craeate a single linked list , like L0 -> L1 -> … -> Ln-1 -> Ln. Write another C fucntion to rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 .You are required to do this in place without altering the nodes’ values.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data; struct Node* next;
} Node;
void InsertData(Node** L) {
  Node *new = (Node*) malloc(sizeof(Node));
  printf("Enter data: ");
  scanf("%d", &new->data);
  new->next = NULL;
  if (!*L) { *L = new; return; }
  Node *p = *L;
  while(p->next != NULL) { p = p->next; }
  p->next = new;
}
void InsertNode(Node** L, Node** newnode) {
  Node *node = *newnode;
  node->next = NULL;
  if (!*L) { *L = node; return; }
  Node *p = *L;
  while(p->next != NULL) { p = p->next; }
  p->next = node;
}
void Display(Node* L) {
  for (Node* p = L; p != NULL; p = p->next) { printf(" %d ->", p->data); }
  printf(" NULL\n");
}
int main() {
  Node *L = NULL, *temp = NULL, *rear = NULL;
  int num;
  printf("Enter the length of linked list: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) { InsertData(&L); }
  int c = 0;
  for (Node* p = L; p != NULL; c++) {
    if (c%2) {
      rear = p;
      while (p->next != NULL) {
        if (p->next->next == NULL) {
          Node *d = p->next;
          p->next = NULL;
          p = d;
          break;
          }
        p = p->next;
      }
    }
    else {
      rear = p->next;
    }
    InsertNode(&temp, &p);
    printf("%d", p->data);
    p = rear;
    if (p->next == NULL && c%2) break;
  }
  Display(temp);
}