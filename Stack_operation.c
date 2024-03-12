#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define a 20

struct stack
{
    int num[a];
    int top;
};
int push(struct stack *s)
{
    int data;
    scanf("%d",&data);
    if(s->top==a-1)
        return 1;
    else
    {
        s->top++;
        s->num[s->top]=data;
        return data;
    }
}
int pop(struct stack *s)
{
    int data;
    if(s->top==-1)
        return 2;
    else
    {
        data=s->num[s->top];
        s->top--;
        return data;
    }
}
void display(struct stack *s)
{
    if(s->top==-1)
        printf("Stack Empty.\n");
    else
    {
        for(int i=s->top;i>=0;i--)
        {
            printf("%d\n",s->num[i]);
        }
    }
}
int peek(struct stack *s)
{
    int data;
    if(s->top==-1)
        return 3;
    else
    {
       data=s->num[s->top];
       return data;
    }
}
int main()
{

   struct stack st;
   struct stack *s;
    s=&st;
    s->top=-1;
    int n,p,q,data;
    scanf("%d",&n);

    if(n>0)
    {
    printf("Stack after PUSH operations is: \n");
    for(int i=0;i<n;i++)
    {
        data=push(s);
        if(data==1)
            printf("Stack Overflow\n");
    }
    scanf("%d",&p);
    for(int i=0;i<p;i++)
    {
        data=push(s);
        if(data==1)
            printf("Stack Overflow\n");
    }
    display(s);
    printf("\n");
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
         data=pop(s);
        if(data==2)
            printf("Stack Underflow\n");
        else
            printf("Popped data is: %d\n",data);
    }
    printf("\nStack after POP operations is: \n");
    display(s);

     printf("\nTop data of stack is: \n");
    data=peek(s);
    if(data==3)
        printf("Stack Empty.\n");
    else
       printf("%d",data);
    }
    else
        printf("Invalid Stack size\n");
    return 0;
}

