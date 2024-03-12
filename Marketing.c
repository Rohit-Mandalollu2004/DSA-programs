#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    char n[20];
    int w,day,mon,yr;
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
        scanf("%s%d%d%d%d",newnode->n,&newnode->w,&newnode->day,&newnode->mon,&newnode->yr);
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
struct node *insert_front(struct node *head)
{
   struct node *newnode=NULL;
    newnode=create();
   if(head==NULL)
       head=newnode;
    else
    {
       newnode->link=head;
        head=newnode;
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
            printf("%s %d %d %d %d\n",cur->n,cur->w,cur->day,cur->mon,cur->yr);
            cur=cur->link;
        }
    }
}

void search(struct node *head)
{
    char ks[20];
    scanf("%s",ks);
    struct node *cur=NULL;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
       cur=head;
        printf("\n%s list is: \n",ks);
        while(cur != NULL)
        {
            if(strcmp(cur->n,ks)==0)
            {
                 printf("%s %d %d %d %d\n",cur->n,cur->w,cur->day,cur->mon,cur->yr);
            }
            cur=cur->link;
        }
    }
}
int main()
{
     struct node *head=NULL;
     int n,c;
     scanf("%d",&n);

     if(n>0)
     {
         for(int i=0;i<n;i++)
             head=insert_end(head);
         scanf("%d",&c);
         for(int i=0;i<c;i++)
             head=insert_front(head);
         printf("Main list is: \n");
         display(head);

         search(head);
     }
    else
        printf("Invalid input\n");
    return 0;
}

