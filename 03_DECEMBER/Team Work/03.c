// Write a C program to create a single linked list then input a value V, partition it such that all nodes less than V come before nodes greater than or equal to V
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data; struct Node* next;
} Node;
void Insert(Node** L, int newdata) {
  Node *new = (Node*) malloc(sizeof(Node));
  if (!newdata) { 
    printf("Enter data: ");
    scanf("%d", &new->data);
  }
  else { new->data = newdata; }
  new->next = NULL;
  if (!*L) { *L = new; return; }
  Node *p = *L;
  while(p->next != NULL) { p = p->next; }
  p->next = new;
}
void Display(Node* L) {
  for (Node* p = L; p != NULL; p = p->next) { printf(" %d ->", p->data); }
  printf(" NULL\n");
}
int main() {
  Node *L = NULL, *temp = NULL;
  int num;
  printf("Enter the length of linked list: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) { Insert(&L, 0); }
  printf("Enter the value of V: ");
  scanf("%d", &num);
  for (Node* p = L; p != NULL; p = p->next) { if (p->data < num) Insert(&temp, p->data); }
  for (Node* p = L; p != NULL; p = p->next) { if (p->data >= num) Insert(&temp, p->data); }
  printf("Previous LL => "); Display(L);
  L = temp;
  printf("After Partition LL => "); Display(L);
}