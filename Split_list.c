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

struct node *insert_end(struct node *head)
{
    struct node *newnode=NULL,*cur=NULL;
    newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link != NULL)
            cur=cur->link;
        cur->link=newnode;

    }
    return head;
}

void split(struct node *head)
{
    struct node *cur=NULL,*cur2=NULL;
    if(head==NULL)
        printf("LIst is empty\n");
    else
    {
        cur=head;
        printf("\n\nList 1 is: \n");
        while(cur != NULL)
        {
            if(cur->num%2 != 0)
            {
                  printf("%d ",cur->num);
            }
            cur=cur->link;
        }
        cur2=head;
        printf("\n\nList 2 is: \n");
        while(cur2 != NULL)
        {
            if(cur2->num%2 == 0)
            {
                  printf("%d ",cur2->num);
            }
            cur2=cur2->link;
        }

    }
}
int main() {
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        printf("Original list is:\n");
        display(head);

        split(head);
    }
    else
        printf("Invalid input\n");
    return 0;
}

