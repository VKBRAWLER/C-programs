#include <stdio.h>

int main() {
    int N;

    // Input the number of elements
    printf("Enter the number of elements: ");
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

    // Reverse the contents of the array
    int start = 0;
    int end = N - 1;
    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    // Print the reversed array
    printf("Reversed array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
