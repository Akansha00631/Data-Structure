#include <stdio.h>

int main() {
    int n, i, target, low, high, mid;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &target);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2; 

        if (arr[mid] == target) {
            printf("Element %d found at position %d.\n", target, mid + 1);
            return 0; 
        } else if (arr[mid] < target) {
            low = mid + 1; 
        } else if {
            high = mid - 1; 
        }
        else
          printf("Element %d not found in the array.\n", target);
    }
     return 0;
}
