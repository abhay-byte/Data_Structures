#include <stdio.h>
#include <stdlib.h>
struct Automobile {
    char type[50];
    char company[50];
    int year;
};

struct Tree {
    struct Automobile data;
    struct Tree* left;
    struct Tree* right;
};

struct TreeNode* createNode(char* type, char* company, int year) {
    struct Tree* N = (struct Tree*)malloc(sizeof(struct Tree));
    strcpy(N->data.type, type);
    strcpy(N->data.company, company);
    N->data.year = year;
    N->left = N->right = NULL;
    return N;
}

struct Tree* Insert(struct Tree* R,char* type, char* company, int year) {
    if (R == NULL) return createNode(type, company, year);
    if (year < R->data.year) R->left = Insert(R->left, type, company, year);
    else R->right = Insert(R->right, type, company, year);
    return R;
}

struct Tree* findMin(struct Tree* N) {
    while (N->left != NULL) N = N->left;
    return N;
}

struct Tree* Delete(struct Tree* R, int year) {
    if (R == NULL) return R;
    if (year < R->data.year)
        R->left = Delete(R->left, year);
    else if (year > R->data.year)
        R->right = Delete(R->right, year);
    else {
        if (R->left == NULL) {
            struct Tree* temp = R->right;
            free(R);return temp;
        } else if (R->right == NULL) {
            struct Tree* temp = R->left;
            free(R);return temp;
        }
        struct Tree* temp = findMin(R->right);
        R->data = temp->data;
        R->right = Delete(R->right, temp->data.year);
    }
    return R;
}

void dispPost(struct Tree* R) {
    if (R != NULL) {
        dispPost(R->left);
        dispPost(R->right);
        display(R);
    }
}
void dispIn(struct Tree* R) {
    if (R != NULL) {
        dispIn(R->left);
        display(R);
        dispIn(R->right);
    }
}
void dispPre(struct Tree* R) {
    if (R != NULL) {
        display(R);
        dispPre(R->left);
        dispPre(R->right);
    }
}

void display(struct Tree* R){
        printf("Type: %s, Company: %s, Year: %d\n",
        R->data.type, R->data.company, R->data.year);
}

void main() {
    struct Tree* R = NULL;
    R = Insert(R, "Sedan", "Tata", 2022);
    R = Insert(R, "SUV", "Nissan", 2020);
    R = Insert(R, "Hatchback", "Ford", 2021);
    R = Insert(R, "Convertible", "Chevrolet", 2019);
    printf("Postorder Traversal:\n");dispPost(R);
    printf("\nInorder Traversal:\n");dispIn(R);
    printf("\nPreorder Traversal:\n");dispPre(R);
    R = Delete(R, 2021);
    printf("\nNode with Year %d Deleted\n", 2021);
    printf("\nInorder Traversal:\n");
    dispIn(R);
    printf("\nAbhay Raj, 00976803122");
}
