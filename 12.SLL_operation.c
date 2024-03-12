#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    char n[20];
    char m[20];
    char p[20];
    int r,s;
    struct node *link;
};
struct node *create()
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated\n");
    else
    {
        scanf("%s%s%s%d%d",newnode->n,newnode->m,newnode->p,&newnode->r,&newnode->s);
        newnode->link=NULL;
    }
    return newnode;
}

struct node *insert_end(struct node *head)
{
   struct node *newnode=NULL;
   struct node *cur=NULL;
    newnode=create();
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
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        cur=head;
        while(cur != NULL)
        {
            printf("%s %s %s %d %d\n",cur->n,cur->m,cur->p,cur->r,cur->s);
            cur=cur->link;
        }
    }
}
int countn(struct node *head)
{
    struct node *cur=NULL;
    int count=0;
    if(head==NULL)
        printf("list empty\n");
    else
    {
        cur=head;
        while(cur != NULL)
        {
            count++;
            cur=cur->link;
        }

    }
    return count;
}

struct node *insert_position(struct node *head)
{
     int pos;
     scanf("%d",&pos);
    struct node *newnode=NULL,*cur=NULL;
    newnode=create();
    int count=0;
    count=countn(head);
    if(head==NULL && pos==1)
        head=newnode;
    else if(pos==1)
    {
        newnode->link=head;
        head=newnode;
    }
    else if(pos>=count+1)
    {
        cur=head;
        while(cur->link != NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    else if(pos>1 && pos<=count)
    {
        cur=head;
        for(int i=1;i<pos-1;i++)
            cur=cur->link;
        newnode->link=cur->link;
        cur->link=newnode;
    }
    else
        printf("Invalid position\n");
    return head;
}
struct node *delete_front(struct node *head)
{
    struct node *temp=NULL;
    if(head==NULL)
        return NULL;
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
     }
    else
    {
        temp=head;
        head=head->link;
        free(temp);
    }
    return head;
}
int main()
{
     struct node *head=NULL;
     int n;
     scanf("%d",&n);

     if(n>0)
     {
         for(int i=0;i<n;i++)
             head=insert_end(head);
         printf("List is: \n");
         display(head);

         head=insert_position(head);
         printf("\nList after insertion is: \n");
         display(head);

         head=delete_front(head);
         printf("\nList after deletion is: \n");
         display(head);
     }
    else
        printf("Invalid input\n");
    return 0;
}

