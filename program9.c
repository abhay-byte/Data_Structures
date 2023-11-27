#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student{
    char name[50];
    int rollNo;
    struct Student *next;
};
void InsertNode(char name[50], int rollNo, struct Student** start, int pos){
    struct Student* ele = (struct Student*)malloc(sizeof(struct Student));
    strcpy(ele->name, name);
    ele->rollNo = rollNo;
    ele->next = NULL;
    if (*start == NULL) *start = ele;
    else{
        if (pos == -1){
            struct Student* ele_next = *start;
            while (ele_next->next != NULL) ele_next = ele_next->next;
            ele_next->next = ele;
            printf("\nNode Added with name %s.", name);
        }
        else{
            int currPos = 1;
            struct Student* ele_next = *start;
            while (ele_next != NULL && pos != currPos)
            {
                ele_next = ele_next->next;
                currPos++;
            }
            if (pos == currPos){
                struct Student* temp = ele_next->next;
                ele_next->next = ele;
                ele->next = temp;
                printf("\nNode Added with name %s.", name);
                printf("\nAt position %i.", pos);
            }
            else printf("\nPosition not found.");
        }
    }
}
void DeleteNodeWithRollNumber(struct Student** start, int rollNo){
    struct Student* ele_next = (*start)->next;
    struct Student* prev = *start;
    while (ele_next != NULL){
        if (rollNo == ele_next->rollNo){
            prev->next = ele_next->next;
            printf("\nNode Deleted.");
            free(ele_next);
            return;
        }
        prev = ele_next;
        ele_next = ele_next->next;
    }
    printf("\nNode to be Deleted not found.");
}
void ReverseLinkedList(struct Student** start){
    struct Student* prev = NULL;
    struct Student* current = *start;
    struct Student* nextNode = NULL;
    while (current != NULL){
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *start = prev;
    printf("\nLinked List Reversed.");
}
void main(){
    struct Student* start = NULL;
    InsertNode("ABC", 1, &start,-1);
    InsertNode("EFG", 2, &start,-1);
    InsertNode("HIK", 3, &start,-1);
    InsertNode("IJK", 4, &start, 2);
    DeleteNodeWithRollNumber(&start, 4);
    ReverseLinkedList(&start);
    printf("\nAbhay Raj, 00976803122");
}
