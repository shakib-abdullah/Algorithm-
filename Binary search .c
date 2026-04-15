
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, target, result;

    //METHOD 1:
//    int arr[] = {2, 5, 8, 12, 23, 38, 56, 72, 91};
//    n = sizeof(arr) / sizeof(arr[0]);
//    printf("Enter target value to search: ");
//    scanf("%d", &target);

    // METHOD 2: USER INPUT
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter target value to search: ");
    scanf("%d", &target);


    result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
