#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dynamicArray; // Declare a pointer for the dynamic array
    int size;

    // Input the size of the dynamic array
    printf("Enter the size of the dynamic array: ");
    scanf("%d", &size);

    // Check if the size is valid
    if (size <= 0) {
        printf("Invalid input. Size must be greater than 0.\n");
        return 1; // Exit with an error code
    }

    // Allocate memory for the dynamic array
    dynamicArray = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (dynamicArray == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    // Input elements into the dynamic array
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &dynamicArray[i]);
    }

    // Print the elements in the dynamic array
    printf("Elements in the dynamic array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamicArray[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(dynamicArray);

    return 0;
}
