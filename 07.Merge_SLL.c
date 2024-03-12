#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    char n[20],c[20];
    int p;
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
        scanf("%s%s%d",newnode->n,newnode->c,&newnode->p);
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
            printf("%s %s %d\n",cur->n,cur->c,cur->p);
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
struct node *merge(struct node *head,struct node *list)
{
    struct node *cur=NULL;
    if(head==NULL && list==NULL)
        return NULL;
    else if(head==NULL)
        return list;
    else if(list==NULL)
        return head;
    else
    {
        cur=head;
        while(cur != NULL)
            cur=cur->link;
        cur->link=list;
    }
    return head;
}
void display2(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        printf("\nStudents with more than 70 points: \n");
        while(cur!=NULL)
        {
            if(cur->p>70)
            {
                 printf("%s %s %d\n",cur->n,cur->c,cur->p);
            }
            cur=cur->link;
        }
    }
}

int main() {
    struct node *head=NULL,*list=NULL;
    int m,n;
    scanf("%d%d",&m,&n);
    if(m>0 && n>0)
    {
        for(int i=0;i<m;i++)
            head=insert_end(head);

        for(int i=0;i<n;i++)
            head=insert_end(head);

        head=merge(head,list);
        printf("Joined list is: \n");
        display(head);

        display2(head);
    }

    else
        printf("Empty List\n");
    return 0;
}
