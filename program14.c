#include <stdio.h>
#include <stdlib.h>
int empNumbers[100];
int front = -1;
int rear = -1;
void Insert(int empNumber) {
    if (rear == 99) {
        printf("Queue Overflow...\n");
        return;
    }
    if (front == -1) front = rear = 0;
    else rear++;
    empNumbers[rear] = empNumber;
    printf("Inserted: %d\n", empNumber);
}
void Delete() {
    if (front == -1) {
        printf("Queue Underflow...\n");
        return;
    }
    int DV = empNumbers[front];
    if (front == rear) front = rear = -1;
    else front++;
    printf("Deleted: %d\n", DV);
}
void display() {
    if (front == -1) printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", empNumbers[i]);
        } printf("\n");
    }
}
void main() {
    Insert(1004);Insert(1005);
    display(); Delete(); display();
    printf("\nAbhay Raj, 00976803122");
}
