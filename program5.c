#include <stdio.h>
//#include <conio.h>
int BinarySearch(int arr[], int lb, int ub, int ele) {
    while (lb <= ub) {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == ele) {
            return mid + 1;
        } else if (arr[mid] < ele) {
            lb = mid + 1;
        } else {
            ub = mid - 1;
        }
    }
    return -1;
}
void main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 42, 47, 50};
    int lb = 0, ub = 9, ele, pos;
    //clrscr();
    printf("Array elements:\n");
    for (int i = lb; i <= ub; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &ele);
    pos = BinarySearch(arr, lb, ub, ele);
    if (pos != -1) {
        printf("Element %d found at position %d\n", ele, pos);
    } else {
        printf("Element %d not found in the array\n", ele);
    }
    printf("\nAbhay Raj, 00976803122");
    //getch();
}
