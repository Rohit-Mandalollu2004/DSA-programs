#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void prime(int n)
{
    int sum=10,status=0,num;
    printf("Students with prime roll numbers = 2 ");
    for(num=3;num<=n;num++)
    {
        status=1;
        for(int i=2;i<num;i++)
        {
             if(num%i == 0)//not divisible condition
             {
                 status=0;
                 break;
             }
        }
        if(status==1)
        {
            sum=sum+10;
            printf("%d ",num);
        }
    }
    printf("\nMoney collected = %d",sum);
}

int main()
{
    int n;
    scanf("%d",&n);

    if(n>1 && n<71)
        prime(n);
    else
        printf("Invalid input\n");
    return 0;
}
