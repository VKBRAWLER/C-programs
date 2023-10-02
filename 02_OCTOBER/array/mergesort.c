// . Write a ‘C’ program to bubble sort and then merge two arrays.
#include <stdio.h>
#include <stdlib.h>
void sort(int *arr, int n) {
    int i,j,temp,sort;
    for (i = 0; i < n-1; i++) {
        sort = 1;
        for (j = 0; j < n-1; j++) {
            if (*(arr + j) > *(arr + i +1) ) {
                temp = *(arr + j);
                *(arr + j) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                sort = 0;
            }
        }
        if (sort) { return; }
    }
}
void merge(int *a1, int a1s, int *a2, int a2s, int *mer) {
    int i;
    for (i = 0; i < a1s; i++) {
        *(mer + i) = *(a1 + i);
    }
    for (i = 0; i < a2s; i++) {
        *(mer + i + a1s) = *(a2 + i);
    }
}
void output(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
int main() {
    int a1[50] = {1,6,8,43,2,4,3,2,1}, a2[50] = {1,6,8,34,2,4,3,2,7,3}, mer[50];
    int a1s = 9, a2s = 10;
    sort(a1, a1s);
    sort(a2, a2s);
    merge(a1, a1s, a2, a2s, mer);
    output(mer, a1s+a2s);
}