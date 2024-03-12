#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define a 10

typedef struct queue
{
    int num[a];
    int front,rear;
}Q;

void enqueue(Q *s,int data)
{
    if(s->rear==a-1)
        printf("Queue ovetflow\n");
    else
    {
        s->rear++;
        s->num[s->rear]=data;
    }
}
int dequeue(Q *s)
{
    int data;
    if(s->front==s->rear)
    {
         return 1;
    }
    else
    {
        s->front++;
        data=s->num[s->front];
        return data;
    }

}
void display(Q *s)
{
    if(s->front==s->rear)
        printf("Queue Empty\n");
    else
    {
        for(int i=s->front+1;i<=s->rear;i++)
        {
            printf("%d ",s->num[i]);
        }
    }
}
int main()
{
    Q st,*s;
    s=&st;
    s->front=s->rear=-1;
    int n,m,data;
    scanf("%d",&n);

    if(n>0 && m>0)
    {
        for(int i=0;i<n;i++)
        {
           scanf("%d",&data);
           enqueue(s,data);
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            data=dequeue(s);
            if(data==1)
                printf("Queue underflow\n");
            else
                 printf("Dequeued %d\n",data);
        }
        printf("Queue after dequeue is: \n");
        display(s);
    }
    else
        printf("Cannot perform operations\n");

    return 0;
}

