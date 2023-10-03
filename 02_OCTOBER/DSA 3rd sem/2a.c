#include <stdio.h>

int main() {
    int N;

    // Input the number of elements
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    // Check if N is within a valid range
    if (N <= 0) {
        printf("Invalid input. Number of elements must be greater than 0.\n");
        return 1; // Exit with an error code
    }

    int arr[N]; // Declare an array of size N to store the elements

    // Input elements into the array
    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the maximum element
    int max = arr[0]; // Assume the first element is the maximum

    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Update max if a larger element is found
        }
    }

    // Print the maximum element
    printf("The maximum element in the array is: %d\n", max);

    return 0;
}
