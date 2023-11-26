#include<stdio.h>
//#include<conio.h>
struct sparse
{
    int row;
    int col;
    int ele;
};
struct sparse s[50];
void main()
{
    int tot_ele, tot_row, tot_col;
    int ptr=1,i,j,k,flag=0;
    int data;
    //clrscr();
    tot_ele=0;
    printf("HOW MANY ROWS ARE THERE IN THE MATRIX ");
    scanf("%d",&tot_row);
    printf("HOW MANY COLS ARE THERE IN THE MATRIX ");
    scanf("%d",&tot_col);
    s[0].row = tot_row;
    s[0].col = tot_col;
    for(i=0; i<tot_row; i++)
    {
        for(j=0; j<tot_col; j++)
        {
            printf("Enter element: ");
            scanf("%d", &data);
            if(data != 0)
            {
                s[ptr].row = i;
                s[ptr].col = j;
                s[ptr].ele = data;
                ptr = ptr + 1;
                tot_ele = tot_ele + 1;
            }
        }
    }
    s[0].ele = tot_ele;
    printf("\n\nROW   COL   DATA\n");
    for(i=0; i<=tot_ele; i++)
    {
        printf("%d  %d  %d\n", s[i].row, s[i].col, s[i].ele);
    }
    ptr=1;
    printf("\nDISPLAYING THE FINAL MATRIX\n");
    for(i=0; i<tot_row; i++)
    {
        for(j=0; j<tot_col; j++)
        {
            if(s[ptr].row==i && s[ptr].col==j)
            {
                printf("%d", s[ptr].ele);
                ptr = ptr + 1;
            }
            else
            {
                printf("  0  ");
            }
        }
        printf("\n");
    }
    printf("\nAbhay Raj, 00976803122");
    //getch();
}
