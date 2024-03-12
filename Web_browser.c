#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char website[50],copyright[20];
    int year;
    struct node *right_link,*left_link;
};
struct node* createnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
        printf("Memory not allocated\n");
    else
    {
        scanf("%s%s%d",newnode->website,newnode->copyright,&newnode->year);
        newnode->right_link=NULL;
        newnode->left_link=NULL;
    }
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *cur=NULL;
    struct node *newnode=createnode();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->right_link!=NULL)
        {
            cur=cur->right_link;
        }
        cur->right_link=newnode;
        newnode->left_link=cur;
    }
    return head;
}
void display_pages(struct node *head,int k,int l)
{
    struct node *cur=NULL;
    printf("%s %s %d\n\n",head->website,head->copyright,head->year);
    cur=head;
    for(int i=0;i<k;i++)
    {
        cur=cur->right_link;
    }
    printf("%s %s %d\n\n",cur->website,cur->copyright,cur->year);
    for(int i=0;i<l;i++)
    {
        cur=cur->left_link;
    }
    printf("%s %s %d\n",cur->website,cur->copyright,cur->year);
}

int main() {
struct node *head=NULL;
int n,k,l;
    scanf("%d",&n);
    if(n>0)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        scanf("%d%d",&k,&l);
        display_pages(head,k,l);

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
