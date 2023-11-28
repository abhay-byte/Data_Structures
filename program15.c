#include <stdio.h>
#include <stdlib.h>
struct Node {
    int empNumber;
    struct Node* next;
};
void Insert(struct Node** front, struct Node** rear, int empNumber) {
    struct Node* N = (struct Node*)malloc(sizeof(struct Node));
    N->empNumber = empNumber; N->next = NULL;
    if (*rear == NULL) *front = *rear = N;
    else {
        (*rear)->next = N;
        *rear = N;
    }
    printf("Inserted: %d\n", empNumber);
}
void Delete(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow...\n");
        return;
    }
    struct Node* FN = *front;
    int DV = FN->empNumber;
    *front = FN->next; free(FN);
    if (*front == NULL) *rear = NULL;
    printf("Deleted: %d\n", DV);
}
void display(struct Node* front) {
    if (front == NULL) printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        struct Node* C = front;
        while (C != NULL) {
            printf("%d ", C->empNumber);
            C = C->next;
        }printf("\n");
    }
}
void main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    Insert(&front, &rear, 1001);
    Insert(&front, &rear, 1002);
    display(front);
    Delete(&front, &rear);
    display(front);
    printf("\nAbhay Raj, 00976803122");
}
