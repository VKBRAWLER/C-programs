// Write a C program to Insert and Delete elements form a Queue using link list ,each node should have the following inforamaion about a product Product_Id(char) , Product_Name(string) , Total_sale(integer),Product_Grade(Char)
#include<stdio.h>
#include<stdlib.h>
typedef struct ProductStruct {
  char Product_Id, Product_Grade;
  char* Product_Name;
  int Total_sale;
  struct ProductStruct* next;
} Product;
int count(Product* rear) {
  int i = 0;
  for (Product* p = rear; p != NULL; p = p->next) { i++; }
  return i;
}
void Insert (Product** front, Product** rear) {
  Product* P = (Product*) malloc(sizeof(Product));
  if (count(*rear) >= 5) { printf("Stack Overflow\n"); return; }
  if (*front) { (*front)->next = P; }
  *front = P;
  if (!*rear) { *rear = P; }
  fflush(stdin);
  printf("Enter Product ID: ");
  scanf("%c", &P->Product_Id);
  printf("Enter Product Name: ");
  scanf("%s", &P->Product_Name);
  printf("Enter Total Sales: ");
  scanf("%d", &P->Total_sale);
  printf("Enter Product Grade: ");
  fflush(stdin);
  scanf("%c", &P->Product_Grade);
  P->next = NULL;
}
void Delete (Product** front, Product** rear) {
  if (!count(*rear)) { printf("Queue Underflow\n"); return; }
  printf("Item %c poped out \n", (*rear)->Product_Id);
  *rear = (*rear)->next;
  if (!*rear) { *front = NULL; }
}
void Display(Product* rear) {
  for (Product* p = rear; p != NULL; p = p->next) { printf(" %c ->", p->Product_Id); }
  printf("NULL\n");
}
int main() {
  Product *front = NULL, *rear = NULL;
  int choice;
  while (1) {
    printf("\nEnter your choice:\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: Insert(&front, &rear); break;
    case 2: Delete(&front, &rear); break;
    case 3: Display(rear); break;
    case 4: printf("Exiting...\n"); free(front); free(rear); exit(0); break;
    default: printf("Invalid Choice\n");
    }
  }
}