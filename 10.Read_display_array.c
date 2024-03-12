#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 100
void read_array(int num[N],int n);
void display_array(int num[N],int n);
int hieghtest(int num[N],int n);
int main()
{
    int n,num[N],max;
    scanf("%d",&n);
    if(n>0)
    {
        read_array(num,n);
        display_array(num,n);
        max=hieghtest(num,n);
        printf("Highest number in array is %d.",max);
    }
    else
        printf("Array cannot be less than 0.");
    return 0;
}
void read_array(int num[N],int n)
{
    int i=0;
    while(i<n)
    {
        scanf("%d",&num[i]);
        i++;
    }
}
void display_array(int num[N],int n)
{
    int i=0;
    while(i<n)
    {
        printf("%d ",num[i]);
        i++;
    }
    printf("\n");
}
int hieghtest(int num[N],int n)
{
    int i=0,max=0;
    while(i<n)
    {
        if(max<num[i])
        {
            max=num[i];
        }
        i++;
    }
    return max;
}


