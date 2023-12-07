// Let A and B be two structures of type Linked List. Write a ‘C ’ program to create a new Linked List ‘S’ that contains elements alternately from A and B beginning with the first element of A. If you run out of elements in one of the lists, then append the remaining
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
void Merge(Node** A, Node** B, Node** S) {
  Node *a = *A, *b = *B, *s = *S;
  for (int c = 1; a != NULL || b != NULL; c++) {
    if (c%2 != 0 && a != NULL) {
      Insert(&*S, a->data); a = a->next;
    }
    else if (b != NULL){
      Insert(&*S, b->data); b = b->next;
    }
  }
}
void Display(Node* L) {
  for (Node* p = L; p != NULL; p = p->next) { printf(" %d ->", p->data); }
  printf(" NULL\n");
}
int main() {
  Node *A = NULL, *B = NULL, *S = NULL, *p = NULL;
  int num;
  printf("Enter the length of A linked list: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) { Insert(&A,0); }
  printf("Enter the length of B linked list: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) { Insert(&B,0); }
  printf("Linked list A => "); Display(A);
  printf("Linked list B => "); Display(B);
  Merge(&A, &B, &S);
  printf("Linked list S => "); Display(S);
}