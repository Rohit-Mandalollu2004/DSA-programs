#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    int n;
    struct node *link;
};
struct node *create_node(struct node *newnode)
{
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("memory not allocated\n");
    else
    {
        scanf("%d",&newnode->n);
        newnode->link=newnode;
    }
    return newnode;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("Empty.\n");
    else
    {
        cur=head;
        do
        {
            printf("%d ",cur->n);
            cur=cur->link;
        }
        while(cur != head);
    }
}
struct node *insert_end(struct node *head)
{

    struct node *cur=NULL,*newnode=NULL;
    newnode=create_node(newnode);
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link != head)
            cur=cur->link;
        cur->link=newnode;
        newnode->link=head;
    }
    return head;
}
struct node *delete_front(struct node *head)
{
    struct node *cur=NULL,*temp=NULL;
    if(head==NULL)
        return NULL;
    else if(head->link==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        temp=head;
        cur=head;
        while(cur->link != head)
        {
            cur=cur->link;
        }
        head=head->link;
        cur->link=head;
        free(temp);
    }
    return head;
}
struct node *delete_end(struct node *head)
{
    struct node *cur=NULL,*prev=NULL;
    if(head==NULL)
        return NULL;
    else if(head->link==head)
    {
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        while(cur->link != head)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=head;
        free(cur);
    }
    return head;
}

int main()
{
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    if(n>=1)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        printf("Circular list is: ");
        display(head);

        head=delete_end(head);
        head=delete_front(head);


        printf("\n\nFinal circular list is: ");
        display(head);
    }
    else
        printf("Invalid input\n");
    return 0;
}
