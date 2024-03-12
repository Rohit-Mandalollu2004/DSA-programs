#include<stdio.h>
main()
{
    int a[30][40],row,col;
    void read_array(int a[30][40],int row,int col);
    void display_array(int a[30][40],int row,int col);
    void sum_upper_triangle(int a[30][40],int row,int col);

    printf("enter no of rows and col\n");
    scanf("%d%d",&row,&col);
    if(row==col)
    {
    if((row>=1 && row<=30) && (col>=1 && col<=40))
    {
         read_array(a,row,col);
       display_array(a,row,col);
      sum_upper_triangle(a,row,col);
    }
    }
    else
        {
              printf("row and col not equal\n");
         }


}

void read_array(int a[30][40],int row,int col)
{
     int i,j;
     printf("enter the array elements\n");
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
            scanf("%d",&a[i][j]);
         }
     }
}

void display_array(int a[30][40],int row,int col)
{
     int i,j;
     printf("the array elements are\n");
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
            printf("%d ",a[i][j]);
         }
        printf("\n");
     }
}

 void sum_upper_triangle(int a[30][40],int row,int col)

{
    int sum=0,i,j;
    float avg;
     for(i=0;i<row;i++)
     {
         for(j=0;j<col;j++)
         {
             if(i>j)
             {
                sum=sum+a[i][j];
             }
         }
     }
     printf("sum of upper triangle w.r.t principal digonal=%d\n",sum);


}
