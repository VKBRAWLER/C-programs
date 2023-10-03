#include <stdio.h>

// Function to check if an element exists in the given array
int elementInArray(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1; // Element found in the array
        }
    }
    return 0; // Element not found in the array
}

// Function to find the intersection of two arrays
void Intersection(int arr1[], int arr2[], int size1, int size2) {
    int intersectionSize = (size1 < size2) ? size1 : size2; // Size of the intersection array cannot exceed the smaller array
    int intersectionArr[intersectionSize]; // Array to store the intersection elements
    int intersectionIndex = 0; // Index to track the current position in the intersection array

    // Iterate through the first array and check if each element is in the second array
    for (int i = 0; i < size1; i++) {
        if (elementInArray(arr2, size2, arr1[i])) {
            if (!elementInArray(intersectionArr, intersectionIndex, arr1[i])) {
                intersectionArr[intersectionIndex++] = arr1[i];
            }
        }
    }

    // Print the intersection array
    printf("Intersection of the two arrays: ");
    for (int i = 0; i < intersectionIndex; i++) {
        printf("%d ", intersectionArr[i]);
    }
    printf("\n");
}

int main() {
    int size1, size2;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    int arr1[size1];

    printf("Enter elements of the first array: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    int arr2[size2];

    printf("Enter elements of the second array: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    Intersection(arr1, arr2, size1, size2);

    return 0;
}
