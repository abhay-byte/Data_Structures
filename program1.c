#include <stdio.h>
//#include <conio.h>
void InsertElement(float arr[], int *n, int k, float item) {
    int j;
    j = *n;
    while (j >= k) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[k] = item;
    (*n)++;
}
void main() {
    float arr[20];
    int n, lb = 0, ub = 9, pos;
    float ele;
    //clrscr();
    for (int i = lb; i <= ub; i++) {
        printf("Element %d: ", i+1);
        scanf("%f", &arr[i]);
    }
    printf("Enter Position:");
    scanf("%d", &pos);
    printf("Insert element: ");
    scanf("%f", &ele);
    InsertElement(arr, &ub, pos - 1, ele);
    printf("\nUpgraded Array:\n");
    for (int i = lb; i <= ub; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\nAbhay Raj, 00976803122");
    //getch();
}
