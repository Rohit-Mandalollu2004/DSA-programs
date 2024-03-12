#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    char song[50],singer[20],movie[20];
    float size;
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
        scanf("%s%s%f%s",newnode->song,newnode->singer,&newnode->size,newnode->movie);
        newnode->right_link=newnode;
        newnode->left_link=newnode;
    }
    return newnode;
}
struct node* insert_end(struct node *head)
{
    struct node *last=NULL;
    struct node *newnode=createnode();
    if(head==NULL)
        head=newnode;
    else
    {
        last=head->left_link;
        last->right_link=newnode;
        newnode->left_link=last;
        newnode->right_link=head;
        head->left_link=newnode;
    }
    return head;
}
void display(struct node *head)
{
    struct node *cur=NULL;
    if(head==NULL)
        printf("List empty\n");
    else
    {
        cur=head;
        do
        {
            printf("%s %s %s %0.2f\n",cur->song,cur->singer,cur->movie,cur->size);
            cur=cur->right_link;
        }while(cur!=head);
    }
}
struct node* insert_details(struct node *head,struct node *newnode,char i_song[20])
{
    struct node *cur=head,*next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        do
        {
            if(strcmp(cur->song,i_song)==0)
            {
                break;
            }
            cur=cur->right_link;
        }while(cur!=head);
        next=cur->right_link;
        cur->right_link=newnode;
        newnode->left_link=cur;
        newnode->right_link=next;
        next->left_link=newnode;

    }
    return head;

}
struct node* delete_song(struct node *head,char i_name[20])
{
    struct node *cur=NULL,*prev=NULL,*next=NULL,*last=NULL;
    if(head==NULL)
        return NULL;
    else if(head->right_link==head)
    {
        if(strcmp(head->song,i_name)==0)
        {
            free(head);
            head=NULL;
        }
    }
     else if(strcmp(head->song,i_name)==0)
    {
        cur=head;
        last=head->left_link;
        head=head->right_link;
        head->left_link=last;
        last->right_link=head;
        free(cur);
    }
    else
    {
        cur=head;
        do
        {
            if(strcmp(cur->song,i_name)==0)
            {
                break;
            }
            cur=cur->right_link;
        }while(cur!=head);

        if(cur!=head)
        {
        prev=cur->left_link;
         next=cur->right_link;
         prev->right_link=next;
        next->left_link=prev;
        free(cur);
        }
    }
    return head;

}
int main() {
struct node *head=NULL;
    int n;
    char i_song[20],i_name[20];
    scanf("%d",&n);
    if(n>3)
    {
        for(int i=0;i<n;i++)
            head=insert_end(head);
        scanf("%s",i_song);
        struct node *newnode=createnode();
        head=insert_details(head,newnode,i_song);
        scanf("%s",i_name);
        head=delete_song(head,i_name);
        display(head);
    }
    else
        printf("Meera cannot create playlist.\n");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
