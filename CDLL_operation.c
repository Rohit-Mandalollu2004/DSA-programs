#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *llink,*rlink;
};

struct node *create_node()
{
    struct node *newn=(struct node *)malloc(sizeof(struct node));
    if(newn==NULL)
        printf("Memory not allocated\n");
    else
    {
        scanf("%d",&newn->num);
        newn->llink=newn;
        newn->rlink=newn;
    }
    return newn;
}

struct node *insert_front(struct node *head)
{
    struct node *last=NULL,*newn=create_node();
    if(head==NULL)
       head=newn;
    else
    {
        last=head->llink;

        newn->rlink=head;
        head->llink=newn;
        last->rlink=newn;
        newn->llink=last;

        head=newn;
    }
    return head;
}

void display_forward(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        do
        {
            printf("%d ",cur->num);
            cur=cur->rlink;
        }
        while(cur != head);
    }
}

void display_reverse(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head->llink;
        do
        {
            printf("%d ",cur->num);
            cur=cur->llink;
        }
        while(cur != head->llink);
    }
}
int main()
{

    struct node *head=NULL;
    int n;
    scanf("%d",&n);

    if(n>0)
    {
        for(int i=0;i<n;i++)
            head=insert_front(head);

        printf("CDLL in forward direction is: \n");
        display_forward(head);

        printf("\n\nCDLL in reverse direction is: \n");
        display_reverse(head);
    }
    else
        printf("Invalid input\n");
    return 0;
}

