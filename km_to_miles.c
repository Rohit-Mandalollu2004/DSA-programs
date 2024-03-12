#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void serie(int n)
{
    int f1=0,f2=1,f3,temp=0,temp2=0;
     for(int i=1;i<=n;i++)
     {
         if(i==n)
         {
            printf("%d ",f1);
            temp=f1;
            temp2=f2;
         }
         else
         {
             printf("%d ",f1);
             f3=f1+f2;
             f1=f2;
             f2=f3;

         }
     }
     printf("\nKilometers = %d kms in Miles = %d miles.",temp,temp2-temp);
     printf("\nMiles = %d miles in Kilometers = %d kms.\n",temp,temp2);
}


int main()
{
    int n;
    scanf("%d",&n);

    if(n>=3 && n<45)
    {
        serie(n);
    }
    else
        printf("Invalid input.\n");
    return 0;
}
