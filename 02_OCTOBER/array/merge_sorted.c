/*Program to merge two sorted arrays*/
#include <stdio.h>
void output(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
}
void merge (int *a1, int *a2, int a1s, int a2s, int *merge_arr) {
    int i;
    for (i = 0; i < a1s; i++) {
        *(merge_arr + i) = *(a1 + i);
    }
    for (i = 0; i < a2s; i++) {
        *(merge_arr + i +a1s) = *(a2 + i);
    }
}
int main() {
    int a1[50] = { 0, 1, 3, 4, 5, 6, 7}, a2[50] = { 0, 1, 2, 3, 4, 5}, a1s = 7, a2s = 6, merge_arr[50];
    merge(a1, a2, a1s, a2s, merge_arr);
    output(merge_arr, a1s+a2s);
}