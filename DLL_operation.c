#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node
{
    double num;
    struct node *llink,*rlink;
};
struct node *create_node()
{
    struct node *newnode=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("memory not allocated\n");
    else
    {
        scanf("%lf",&newnode->num);
        newnode->llink=NULL;
        newnode->rlink=NULL;
    }
    return newnode;
}


struct node *insert_end_dll(struct node *head)
{
    struct node *newnode=NULL,*cur=NULL;
    newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->rlink != NULL)
        {
            cur=cur->rlink;
        }
        cur->rlink=newnode;
        newnode->llink=cur;
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
        while(cur != NULL)
        {
            printf("%0.2lf ",cur->num);
            cur=cur->rlink;
        }
    }

}
void display_reverse(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("list is empty\n");
    else
    {
        cur=head;
        while(cur->rlink != NULL)
        {
            cur=cur->rlink;
        }
        while(cur != NULL)
        {
            printf("%0.2lf ",cur->num);
             cur=cur->llink;
        }
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
            head=insert_end_dll(head);
        printf("DLL in forward direction: \n");
        display_forward(head);
        printf("\n\nDLL in reverse direction: \n");
        display_reverse(head);

    }
    else

        printf("N should be positive.\n");
    return 0;
}

