#include<stdio.h>
//#include<conio.h>
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
void main()
{
    int LA[20];
    int i,K,LB,UB,POS,ELE;
    //clrscr();
    LB=0;
    UB=9;
    for(i=LB;i<=UB;i++)
    {
        printf("ENTER ELEMENT OF ARRAY");
        scanf("%d",&LA[i]);
    }
    printf("ENTER ELEMENT TO INSERT IN ARRAY");
    scanf("%d",&ELE);
    for(i=LB;i<=UB;i++)
    {
        if(LA[i] <= ELE && LA[i+1] >= ELE)
        {
            POS=i+1;
            break;
        }
    }
    INSERT(LA, &UB, POS, ELE);
    K=LB;
    while(K<=UB)
    {
        printf("%d %d\n",K,LA[K]);
        K=K+1;
    }
    printf("\nAbhay Raj, 00976803122");
    //getch();
}
