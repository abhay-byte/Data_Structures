#include <stdio.h>
#include <stdlib.h>
void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        Swap(&arr[minIndex], &arr[i]);
    }
}
void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
}
void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }arr[j + 1] = key;
    }
}
void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
int Partition(int arr[], int low, int high) {
    int pi = arr[high], i = low - 1;
    for (int j = low; j <= high - 1; j++)
        if (arr[j] < pi) Swap(&arr[++i], &arr[j]);
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        int i, j, k, n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
        for (i = 0; i < n1; L[i] = arr[l + i], i++);
        for (j = 0; j < n2; R[j] = arr[m + 1 + j], j++);
        for (i = 0, j = 0, k = l; i < n1 && j < n2;)
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
}
void RadixSort(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    for (int e = 1; max / e > 0; e *= 10) {
        int r = 10;
        int *o = (int *)malloc(n * sizeof(int)), c[r];
        for (int i = 0; i < r; c[i++] = 0);
        for (int i = 0; i < n; c[(a[i] / e) % r]++, i++);
        for (int i = 1; i < r; c[i] += c[i - 1], i++);
        for (int i = n - 1; i >= 0; o[--c[(a[i] / e) % r]] = a[i], i--);
        for (int i = 0; a[i] = o[i], i < n; i++);
    }
}
void Print(int arr[], int n) {
    for (int i = 0; i < n; printf("%d ", arr[i++]));
    printf("\n");
}
void Swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}
int main() {
    int arr[] = {56, 77, 23, 99, 68, 11, 9, 29, 33, 45, 10, 87};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: "); Print(arr, n);
    SelectionSort(arr, n), printf("Selection Sort: "), Print(arr, n);
    BubbleSort(arr, n), printf("Bubble Sort: "), Print(arr, n);
    InsertionSort(arr, n), printf("Insertion Sort: "), Print(arr, n);
    QuickSort(arr, 0, n - 1), printf("Quick Sort: "), Print(arr, n);
    MergeSort(arr, 0, n - 1), printf("Merge Sort: "), Print(arr, n);
    RadixSort(arr, n), printf("Radix Sort: "), Print(arr, n);
    printf("Abhay Raj, 00976803122");
}
