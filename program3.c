#include <stdio.h>
//#include <conio.h>
void DeleteElement(float arr[], int *ub, float element) {
    int pos = -1;
    for (int i = 0; i <= *ub; i++) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < *ub; i++) {
            arr[i] = arr[i + 1];
        }
        (*ub)--;
    }
}
void main() {
    float arr[20];
    int lb = 0, ub = 9;
    float ele;
    //clrscr();
    for (int i = lb; i <= ub; i++) {
        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }
    printf("Enter the element to be deleted: ");
    scanf("%f", &ele);
    DeleteElement(arr, &ub, ele);
    printf("\nUpgraded Array:\n");
    for (int i = lb; i <= ub; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\nAbhay Raj, 00976803122");
//    getch();
}
