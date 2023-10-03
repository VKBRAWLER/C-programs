#include <stdio.h>

// Function to check if an element exists in the union array
int isElementInUnion(int unionArr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (unionArr[i] == element) {
            return 1; // Element found in the union array
        }
    }
    return 0; // Element not found in the union array
}

// Function to find the union of two arrays
void findUnion(int arr1[], int arr2[], int size1, int size2) {
    int unionSize = size1 + size2;
    int unionArr[unionSize]; // Array to store the union elements
    int unionIndex = 0; // Index to track the current position in the union array

    // Traverse the first array and add unique elements to the union array
    for (int i = 0; i < size1; i++) {
        if (!isElementInUnion(unionArr, unionIndex, arr1[i])) {
            unionArr[unionIndex++] = arr1[i];
        }
    }

    // Traverse the second array and add unique elements to the union array
    for (int i = 0; i < size2; i++) {
        if (!isElementInUnion(unionArr, unionIndex, arr2[i])) {
            unionArr[unionIndex++] = arr2[i];
        }
    }

    // Print the union array
    printf("Union of the two arrays: ");
    for (int i = 0; i < unionIndex; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {3, 4, 5, 6, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    findUnion(arr1, arr2, size1, size2);

    return 0;
}
