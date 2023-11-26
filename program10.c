#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Employee
{
    char name[50];
    int empId;
    struct Employee* next;
    struct Employee* prev;
};
void InsertAtFront(struct Employee **start, char name[50], int empId)
{
    struct Employee* ele = (struct Employee*)malloc(sizeof(struct Employee));
    strcpy(ele->name,name);
    ele->empId = empId;
    ele->next = NULL;
    ele->prev = NULL;
    if (*start == NULL)
        *start = ele;
    else
    {
        struct Employee* ele_curr = *start;
        ele_curr->prev = ele;
        ele->next = ele_curr;
    }
    printf("\nNode Added with name %s.", name);
}
void DeletetionAtEnd(struct Employee **start)
{
    if (*start!=NULL)
    {
        struct Employee* ele_curr = *start;
        while (ele_curr->next != NULL)
        {
            ele_curr = ele_curr->next;
        }
        struct Employee* temp = ele_curr->prev;
        temp->next = NULL;
        printf("\nNode Deleted.");
        free(ele_curr);
    } else printf("Linked List Empty.");
}
int main()
{
    struct Employee *start = NULL;
    InsertAtFront(&start,"ABC",001);
    InsertAtFront(&start,"EFG",002);
    InsertAtFront(&start,"IJK",003);
    DeletetionAtEnd(&start);
    printf("\nAbhay Raj, 00976803122");
}
