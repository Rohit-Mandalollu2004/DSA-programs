#include<stdio.h>
#include<stdlib.h>

struct date
{
    int d;
    int m;
    int y;

};
void readdate(struct date *D);
void displaydate(struct date *D);
int isleap(int y);
int checkdate(struct date *D);
int main()
{
    struct date *D;
    D=(struct date *)malloc(sizeof(struct date));
    readdate(D);
    displaydate(D);

    int c=checkdate(D);

    if(c==1)
        printf("date is valid\n");
    else
        printf("date is invalid\n");
}

void readdate(struct date *D)
{
    printf("enter date in the  form of dd-mm-yyyy format:\n");
    scanf("%d%*c",&D->d);
    scanf("%d%*c",&D->m);
    scanf("%d",&D->y);
}
void displaydate(struct date *D)
{
    printf("%d-",D->d);
    printf("%d-",D->m);
    printf("%d\n",D->y);
}
int checkdate(struct date *D)
{
    if(D->m >=13)
        return 0;
    if(D->d >=32)
        return 0;
    if(D->m==2)
    {
        if(D->d >=30)
            return 0;
        int L=isleap(D->y);

        if(L==0)
        {
            if(D->d >=29)
                return 0;

        }
    }
    if(D->m==4 || D->m==6 || D->m==9 || D->m==11)
    {
        if(D->d >=31)
            return 0;
    }
    return 1;
}
int isleap(int y)
{
    if(y%400==0)
        return 1;
    else if(y%100==0)
        return 0;
    else if(y%4==0)
        return 1;
    else
        return 0;
}
