#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define R 10

//fn pro
void read_array(int marks[R],int n);
void display_array(int marks[R], int n);


int main()
{

    int marks[R];
    int n;
    scanf("%d",&n);
    if(n>5 && n<11)
    {

        read_array(marks,n);
        display_array(marks,n);
    }
    else
        printf("Subjects cannot be less than 6 and more than 10.");
    return 0;
}
void read_array(int marks[R],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
         scanf("%d",&marks[i]);
    }

}

void  display_array(int marks[R], int n)
{
    int i,j,max=0,sum=0;
    float percent;
    for(i=0;i<n;i++)
    {
        sum=sum+marks[i];
        printf("%d ",marks[i]);
    }
    percent=(float)sum/n;

    printf("\n");
    printf("Percentage: %0.2f",percent);
    printf("\n");

    for(j=0;j<n;j++)
    {
        if(max<marks[j])
         max=marks[j];
    }
    printf("Highest marks: %d",max);
}
