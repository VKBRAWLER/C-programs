// Write a C program to create two single linked lists, and then write another function to subtract two numbers represented as linked list.
// List1->; 8->9->7->NULL (First Number: 897)
// List2->: 1->4->5->NULL (Second Number: 145)
// Output->:752
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data; struct Node* next;
} Node;
void Insert(Node** L, int newdata) {
  Node *new = (Node*) malloc(sizeof(Node));
  new->data = newdata;
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
  int num1, num2, num3;
  Node *n1 = NULL, *n2 = NULL, *n3 = NULL;
  printf("Enter First Number: ");
  scanf("%d", &num1);
  printf("Enter Second Number: ");
  scanf("%d", &num2);
  for (; num1 || num2 ; num1 /= 10, num2 /= 10) {
    Insert(&n1, num1%10);
    Insert(&n2, num2%10);
  }
  for (Node *p1 = n1, *p2 = n2 ; p1 != NULL || p2 != NULL; p1 = p1->next, p2 = p2->next) {
    Insert(&n3, p1->data - p2->data);
    }
    printf("List 1 => ");
    Display(n1);
    printf("List 2 => ");
    Display(n2);
    printf("Output -> ");
  for (Node* p = n3; p != NULL; p = p->next) { printf("%d", p->data); }
}