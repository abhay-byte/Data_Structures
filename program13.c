#include <stdio.h>
#include <stdlib.h>
struct Node {
    int rollNumber;
    struct Node* next;
};
void push(struct Node** start, int rollNumber) {
    struct Node* N = (struct Node*)malloc(sizeof(struct Node));
    N->rollNumber = rollNumber;
    N->next = *start; *start = N;
    printf("Pushed: %d\n", rollNumber);
}
int pop(struct Node** start) {
    if (*start == NULL) {
        printf("Stack Underflow...\n");
        return -1;
    }
    struct Node* PN = *start;
    int PV = PN->rollNumber;
    *start = PN->next;
    free(PN); return PV;
}
void display(struct Node* start) {
    if (start == NULL) printf("Stack is empty.\n");
    else {
        printf("Stack elements: ");
        struct Node* current = start;
        while (current != NULL) {
            printf("%d ", current->rollNumber);
            current = current->next;
        } printf("\n");
    }
}
void main() {
    struct Node* start = NULL;
    push(&start, 101); push(&start, 102);
    display(start);
    int PV = pop(&start);
    if (PV != -1) printf("Popped Value: %d\n", PV);
    display(start);
    printf("\nAbhay Raj, 00976803122");
}
