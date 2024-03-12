#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void addition(int num)
{
    int digit,sum=0;
    while(num != 0)
    {
       digit=num%10;
       printf("%d\n",digit);
       sum=sum+digit;
       num=num/10;
    }
    printf("Sum of all digits = %d\n",sum);
    if(sum%2 == 0)
        printf("ITS ALBERTS LUCKY NUMBER\n");
    else
        printf("ITS NOT ALBERTS LUCKY NUMBER\n");
}
int main() {

    int num;
    scanf("%d",&num);

    if(num>9)
        addition(num);
    else
        printf("Number should have more than one digit\n");
    return 0;
}
