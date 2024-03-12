#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define R 10
#define C 10



void read_2darray(int N[R][C],int m,int n);
void display_2darray(int N[R][C],int m,int n);
void row_sum(int N[R][C],int m,int n,int sum[R]);
void max_array(int N[R][C],int m,int n,int sum[R]);


int main()
{

    int N[R][C],sum[R];
    int m,n;
    scanf("%d%d",&m,&n);
    if(m>5 && n==3)
    {
         read_2darray(N,m,n);
         display_2darray(N,m,n);
         row_sum(N,m,n,sum);
         max_array(N,m,n,sum);
    }
    else
        printf("Invalid players or game formats");
    return 0;
}
void read_2darray(int N[R][C],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&N[i][j]);

    }

}
void display_2darray(int N[R][C],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",N[i][j]);

        }
        printf("\n");


    }
    printf("\n");



}
void row_sum(int N[R][C],int m,int n,int sum[R])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        sum[i]=0;
        for(j=0;j<n;j++)
        {
            sum[i]=sum[i]+N[i][j];
        }
        printf("Player %d: %d\n",i+1,sum[i]);


    }

    printf("\n");

}
void max_array(int N[R][C],int m,int n,int sum[R])
{

    int i,max=0,s=0;
    for(i=0;i<m;i++)
    {
         if(max<sum[i])
         {
            max=sum[i];
            s=i;
         }
    }
    printf("Player %d has highest total runs scored of %d",s+1,max);



}
