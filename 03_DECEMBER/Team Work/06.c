//. Write a C program to create two link lists positive and negative from Original linked list, so that  positive linked list contains all positive elements and negative linked list contains negative elements.  Positive and negative linked lists should use the node of existing original linked list.
#include<stdio.h>
typedef struct Node {
  int data; struct Node* next;
} Node;
void InsertData(Node** L) {
  Node *newNode = (Node*) malloc(sizeof(Node));
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  if (!*L) { *L = newNode; return; }
  Node *p = *L;
  while(p->next != NULL) { p = p->next; }
  p->next = newNode;
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
  Node *L = NULL, *positive = NULL, *negetive = NULL, *rear = NULL;
  int num;
  printf("Enter the length of linked list: ");
  scanf("%d", &num);
  for (int i = 0; i < num; i++) { InsertData(&L); }
  for (Node* p = L; p != NULL;) {
    rear = p->next;
    if (p->data >= 0) { InsertNode(&positive, &p); }
    else { InsertNode(&negetive, &p); }
    p = rear;
  }
  printf("Positive: ");
  Display(positive);
  printf("Negetive: ");
  Display(negetive);
}   