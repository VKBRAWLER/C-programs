/*Program to insert an element at a given position in an array*/
#include<stdio.h>
void input(int *arr, int n) {
    int i;
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }
}
void output(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
void insert(int *arr, int *n, int num, int position) {
    int i;
    *n = *n + 1;
    for (i = *n - 1; i > position; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + position) = num;
}
int main() {
    int arr[50], n, num, position;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    input(arr, n);
    printf("Current array is\n");output(arr, n);
    printf("\nEnter the number you want to insert: ");
    scanf("%d", &num);
    printf("Enter the position where to insert: ");
    scanf("%d", &position);
    insert(arr, &n, num, --position);
    printf("New array is\n");output(arr, n);
}