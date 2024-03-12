
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void number(int n,int num)
{
    int esum=0,osum=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        if(num%2 == 0)
        {
           esum+=num;
        }
        else
        {
           osum+=num;
        }
    }
    printf("Sum of even numbers=%d\n",esum);
    printf("Sum of odd numbers=%d",osum);
}
int main()
{
    int n,num;
    scanf("%d",&n);

    if(n>0)
    {
         number(n,num);
    }
    else
        printf("Invalid input\n");
    return 0;
}
