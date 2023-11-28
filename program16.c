#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Lab {
    char name[50];
    int num;
    struct Lab* next;
};
void Insert(struct Lab** front, struct Lab** rear, const char* name, int num) {
    struct Lab* N = (struct Lab*)malloc(sizeof(struct Lab));
    strcpy(N->name, name);
    N->num = num;
    N->next = NULL;
    if (*rear == NULL) *front = *rear = N;
     else {
        (*rear)->next = N;
        *rear = N;
    }
    printf("Inserted: Lab Name: %s, Lab Number: %d\n", N->name, N->num);
}
void Delete(struct Lab** front, struct Lab** rear) {
    if (*front == NULL) {
        printf("Queue Underflow...\n");
        return;
    }
    struct Lab* FN = *front;
    printf("Deleted: Lab Name: %s, Lab Number: %d\n", FN->name, FN->num);
    *front = FN->next; free(FN);
    if (*front == NULL) *rear = NULL;
}
void Display(struct Lab* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Lab* c = front;
    printf("Queue elements:\n");
    do {
        printf("Lab Name: %s, Lab Number: %d\n", c->name, c->num);
        c = c->next;
    } while (c != front && c!= NULL);
}
int main() {
    struct Lab* front = NULL;
    struct Lab* rear = NULL;
    Insert(&front, &rear, "Physics Lab", 24);
    Insert(&front, &rear, "Chemistry Lab", 17);
    Insert(&front, &rear, "Biology Lab", 9);
    Display(front); Delete(&front, &rear);
    Display(front);
    printf("\nAbhay Raj, 00976803122");
}
