#include<stdio.h>
#include<conio.h>
void INSERT(int LA[], int *N, int K, int ITEM)
{
int J;
J=*N;
while(J>=K)
{
LA[J+1]=LA[J];
J=J-1;
}
LA[K]=ITEM;
*N=*N+1;
}
void main() {
    int LA[20];
    int i, K, LB, UB;
    LB = 0;
    UB = 9;
    clrscr();
    for (i = LB; i <= UB; i++) {
        printf("ENTER ELEMENT OF ARRAY");
        scanf("%d", &LA[i]);
    }
    INSERT(LA, &UB, 5, 999);
    K = LB;
    while (K <= UB) {
        printf("%d %d\n", K, LA[K]);
        K = K + 1;

    }
    printf("\nName: Abhhay Raj");
    printf("\nEnrollment Number: 00976803122");
    getch();
}