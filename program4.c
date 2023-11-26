#include <stdio.h>
//#include <conio.h>
int linearSearch(int arr[], int lb, int ub, int ele) {
    for (int i = lb; i <= ub; i++) {
        if (arr[i] == ele) {
            return i + 1;
        }
    }
    return -1;
}
void main() {
    int arr[20];
    int lb = 0, ub=9, size, ele, pos;
    //clrscr();
    for (int i = lb; i <= ub; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &ele);
    pos = linearSearch(arr, lb, ub, ele);
    if (pos != -1) {
        printf("Element %d found at position %d\n", ele, pos);
    } else {
        printf("Element %d not found.\n", ele);
    }
    printf("\nAbhay Raj, 00976803122");
//    getch();
}
