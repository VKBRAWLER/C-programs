// Write a C program to Insert and Delete elements form a Queue using link list ,each node should have the following inforamaion about a product Product_Id(char) , Product_Name(string) , Total_sale(integer),Product_Grade(Char)
#include<stdio.h>
#include<stdlib.h>
typedef struct ProductStruct {
  char Product_Id;
  char* Product_Name;
  int Total_sale;
  char Product_Grade;
  int position;
  struct ProductStruct* next;
} Product;
int count(Product* rear) {
  int i = 0;
  Product* p = rear;
  while (p != NULL) {
    i++;
    p = p->next;
  }
  return i;
}
void Insert (Product** front, Product** rear) {
  Product* P = (Product*) malloc(sizeof(Product*));
  if (count(*rear) >= 5) { printf("Stack Overflow\n"); return; }
  if (*front) { (*front)->next = P; }
  *front = P;
  if (!*rear) { *rear = P; }
  fflush(stdin);
  printf("Enter Product ID: ");
  scanf("%c", &P->Product_Id);
  P->next = NULL;
}
void Delete (Product** front, Product** rear) {
  if (!count(*rear)) { printf("Queue Underflow\n"); return; }
  printf("Item %c poped out \n", (*rear)->Product_Id);
  *rear = (*rear)->next;
  if (!*rear) { *front = NULL; }
}
void Display(Product* rear) {
  Product* p = rear;
  while (p != NULL) {
    printf(" %c ->",p->Product_Id);
    p = p->next;
  }
  printf("NULL\n");
}
int main() {
  Product* front = NULL;
  Product* rear = NULL;
  int choice;
  while (1) {
    printf("Enter your choice: ");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      Insert(&front, &rear);
      break;
    case 2:
      Delete(&front, &rear);
      break;
    case 3:
      Display(rear);
      break;
    default:
    free(front);
    free(rear);
      exit(1);
      break;
    }
  }
}