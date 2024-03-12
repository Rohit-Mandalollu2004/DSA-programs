#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define R 100
#define C 100


//fn portotype
void read_2darray(int num[R][C],int m,int n);
void display_2darray(int num[R][C],int m,int n);


int main()
{

    int num[R][C];
    int m,n;
    scanf("%d%d",&m,&n);
    if(m>0 && n>0)
    {
        read_2darray(num,m,n);
        display_2darray(num,m,n);
    }
    else
        printf("Rows and columns should be more than 0.");
    return 0;
}
void read_2darray(int num[R][C],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&num[i][j]);

    }
}
void display_2darray(int num[R][C],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",num[i][j]);

        }
        printf("\n");
    }

}


