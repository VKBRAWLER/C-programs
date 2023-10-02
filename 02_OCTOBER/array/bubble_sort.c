#include <stdio.h>
#include <stdlib.h>
void output(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
void bbl(int *arr, int n) {
    int i,j, swap, temp;
    for (i = 0; i < n-1; i++) {
        swap = 0;
        for (j = 0; j < n-1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                swap = 1;
            }
        }
        if (!swap) { return;}
    }
}
int main() {
    int arr[50] = {1,6,8,43,2,4,3,2,1}, a1=9;
    bbl(arr, a1);
    output(arr, a1);
}