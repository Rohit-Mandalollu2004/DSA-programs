#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{

    int num;
    struct node *link;
};

struct node *create_node()
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated\n");
    else
    {
        scanf("%d",&newnode->num);
        newnode->link=NULL;
    }
    return newnode;
}

void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d ",cur->num);
            cur=cur->link;
        }
    }
}

struct node *insert_front(struct node *head)
{
    struct node *newnode=NULL;
    newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
       newnode->link=head;
        head=newnode;
    }
    return head;
}

struct node *reverse(struct node *head)
{
    struct node *cur=NULL,*prev=NULL,*next=NULL;
    if(head==NULL)
        printf("List is empty\n");
    else if(head->link==NULL)
        return head;
    else
    {
        cur=head;
        while(cur != NULL)
        {
            next=cur->link;
            cur->link=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
    }
    return head;
}
int main() {
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
            head=insert_front(head);
        printf("List is:\n");
        display(head);

        head=reverse(head);
        printf("\n\nReversed list is: \n");
        display(head);
    }
    else
        printf("Invalid input\n");
    return 0;
}

