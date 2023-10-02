/*Program to delete an element from an array*/
#include<stdio.h>
void output(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
void delete( int *arr, int *n, int num) {
    int i = 0, index = -1;
    for (i = 0; i < *n; i++){
        if ( *(arr+i) == num) {
            index = i;
            break;
        }
    }
    if (index == -1) { printf("Element not found\n"); return; } 
    for (index; index < *n; index++) {
        *(arr+index) = *(arr+index+1);
    }
    (*n)--;
}
int main() {
    int n = 6, num, arr[50] = { 0, 1, 2, 3, 4, 5};
    printf("Enter a number to delete: ");
    scanf("%d", &num);
    delete(arr, &n, num);
    output(arr, n);
}