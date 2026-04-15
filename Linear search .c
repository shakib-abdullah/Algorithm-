#include <stdio.h>

int main() {
    int n, i, search, found = 0;

//    // --- WAY 1: Value Declaration (Pre-defined) ---
//    int arr[] = {10, 25, 30, 45, 50};
//    n = 5;


    // --- WAY 2: User Input ---
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Enter number to search: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++) {
        if(arr[i] == search) {
            printf("%d found at index %d.\n", search, i);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("%d is not present in the array.\n", search);
    }

    return 0;
}
