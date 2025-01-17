#include <stdio.h>

int main() {
    int n, i, target, found = 0;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform Linear Search
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            printf("Element %d found at position %d.\n", target, i + 1);
            found = 1; // Set flag to indicate the element is found
            break;     // Exit the loop as the element is found
        }
    }

    // If the element is not found
    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
