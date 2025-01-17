#include <stdio.h>

int main() {
    int n, i, target, low, high, mid;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare the array

    // Input sorted array elements
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Initialize search boundaries
    low = 0;
    high = n - 1;

    // Perform Binary Search
    while (low <= high) {
        mid = (low + high) / 2; // Find the middle element

        if (arr[mid] == target) {
            printf("Element %d found at position %d.\n", target, mid + 1);
            return 0; // Exit the program as the element is found
        } else if (arr[mid] < target) {
            low = mid + 1; // Focus on the right half
        } else {
            high = mid - 1; // Focus on the left half
        }
    }

    // If the element is not found
    printf("Element %d not found in the array.\n", target);

    return 0;
}
