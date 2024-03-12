#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    char n[20],c[20],p[20];
    int wt,tt;
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
        scanf("%s%s%s%d%d",newnode->n,newnode->c,newnode->p,&newnode->wt,&newnode->tt);
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
            printf("%s %s %s %d %d\n",cur->n,cur->c,cur->p,cur->wt,cur->tt);
            cur=cur->link;
        }
    }
}

struct node *insert_end(struct node *head)
{
    struct node *cur=NULL,*newnode=NULL;
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
struct node *delete_min(struct node *head)
{
    struct node *cur=NULL,*low=NULL,*prev=NULL,*prevlow=NULL;
    int min=999;

    if(head==NULL)
        return NULL;
    else
    {
        cur=head;
        while(cur != NULL)
        {
            if(cur->wt<min)
            {
                min=cur->wt;
                low=cur;
                prevlow=prev;

            }
            prev=cur;
            cur=cur->link;
        }
        if(head==low)
        {
           head=head->link;
            free(low);
        }
        else
        {
            prevlow->link=low->link;
            free(low);
        }
    }
    return head;
}

struct node *search_delete(struct node *head)
{
    char kname[20];
    scanf("%s",kname);
    struct node *cur=NULL,*kn=NULL,*prev=NULL,*prevkn=NULL;
    int status=0;


    if(head==NULL)
        return NULL;
    else
    {
        cur=head;
        while(cur != NULL)
        {
            if(strcmp(cur->n,kname)==0)
            {
                status=1;
                kn=cur;
                prevkn=prev;

            }
            prev=cur;
            cur=cur->link;
        }
        if(status==1)
        {
            if(head==kn)
           {
               head=head->link;
               free(kn);
            }
           else
           {
            prevkn->link=kn->link;
            free(kn);
           }
        }
        else
            printf("name not found\n");
    }
    return head;
}
void find_max(struct node *head)
{
    struct node *cur=NULL,*high=NULL;
    int max=-1;

    if(head==NULL)
        printf("List is empty\n");
    else
    {
        cur=head;
        printf("\nSelected candidate is: \n");
        while(cur != NULL)
        {
            if(cur->tt>max)
            {
                max=cur->tt;
                high=cur;
            }
            cur=cur->link;
        }
        printf("%s %s %s %d %d\n",high->n,high->c,high->p,high->wt,high->tt);

    }
}

int main()
{
    struct node *head=NULL;
    int n;
    scanf("%d",&n);
    if(n>=5)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);

        head=delete_min(head);
        head=search_delete(head);

        printf("Final list is: \n");
        display(head);

        find_max(head);
    }
    else
        printf("Invalid input\n");
    return 0;
}

