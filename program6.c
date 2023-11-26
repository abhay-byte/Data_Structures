#include <stdio.h>
//#include <conio.h>
int BinarySearch(int arr[], int lb, int ub, int ele) {
    if (lb <= ub) {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == ele) {
            return mid + 1;
        } else if (arr[mid] < ele) {
            return BinarySearch(arr, mid + 1, ub, ele);
        } else {
            return BinarySearch(arr, lb, mid - 1, ele);
        }
    }
    return -1;  // Return -1 if ele is not found
}
void main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 42, 47, 50};
    int lb = 0, ub = 9, ele, position;
    printf("Array elements:\n");
    for (int i = lb; i <= ub; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &ele);
    position = BinarySearch(arr, lb, ub, ele);
    if (position != -1) {
        printf("Element %d found at position %d\n", ele, position);
    } else {
        printf("Element not found in the array.");
    }
    printf("\nAbhay Raj, 00976803122");
    //getch();
}
