#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char collegeName[50];
    int rank;
    struct Node* next;
};
void insertAtFront(struct Node** start, char* name, int rank) {
    struct Node* N = (struct Node*)malloc(sizeof(struct Node));
    strcpy(N->collegeName, name);
    N->rank = rank;
    if (*start == NULL) {
        N->next = N;
        *start = N;
    } else {
        N->next = (*start)->next;
        (*start)->next = N;
    }
}
void insertAtEnd(struct Node** start, char* name, int rank) {
    struct Node* N = (struct Node*)malloc(sizeof(struct Node));
    strcpy(N->collegeName, name);
    N->rank = rank;
    if (*start == NULL) {
        N->next = N;
        *start = N;
    } else {
        N->next = (*start)->next;
        (*start)->next = N;
        *start = N;
    }
}
void main() {
    struct Node* start = NULL;
    printf("Node with College A and rank 1, inserted at front.\n");
    insertAtFront(&start, "College A", 1);
    printf("Node with College B and rank 5, inserted at front.");
    insertAtEnd(&start, "College B", 5);
    printf("\nAbhay Raj, 00976803122");
}
