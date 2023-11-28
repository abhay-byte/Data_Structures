#include <stdio.h>
int stack[100], top = -1;
void push(int rollNumber) {
    if (top == 99) printf("Stack Overflow...\n");
    else {
        top++; stack[top] = rollNumber;
        printf("Pushed: %d\n", rollNumber);
    }
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow...\n");
        return -1;
    } else {
        int PV = stack[top];
        top--; return PV;
    }
}
void display() {
    if (top == -1) printf("Stack is empty.\n");
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
void main() {
    push(10); push(20); display();
    int PV = pop();
    if (PV != -1) printf("Popped Value: %d\n", PV);
    display();
    printf("\nAbhay Raj, 00976803122");
}
