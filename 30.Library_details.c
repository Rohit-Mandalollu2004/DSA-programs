#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include"sort.h"

struct book
{
    int sno;
    char *tittle;
    int rno;
    int days;
};
void readbook(struct book *B,int n);
void displaybook(struct book *B,int n);
int cmpSno(void *a,void *b);

int main()
{
    struct book *B;
    int n;
    printf("enter the number of books borrowed by students:");
    scanf("%d",&n);
    B=(struct book *)malloc(sizeof(struct book)*n);
    readbook(B,n);
    displaybook(B,n);
    selectionSort(B,n,sizeof(struct book),cmpSno);
    displaybook(B,n);


}
void readbook(struct book *B,int n)
{
    int i;
    char str[20];
    for(i=0;i<n;i++)
    {
        printf("enter sno:\n");
        scanf("%d",&B[i].sno);

        printf("enter the tittle of book:\n");
        scanf("%s",str);

        B[i].tittle=(char *)malloc(strlen(str)+1);
        strcpy(B[i].tittle,str);


        printf("enter rno of student who borrowed this book:\n");
        scanf("%d",&B[i].rno);

        printf("enter the no of days for that student has given late book:\n");
        scanf("%d",&B[i].days);
    }
}
void displaybook(struct book *B,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("sno of book is:%d\n",B[i].sno);
        printf("tittle of the book:%s\n",B[i].tittle);
        printf("rno:%d\n",B[i].rno);
        printf("days to fined:%d\n",B[i].days);

    }
}
int cmpSno(void *a,void *b)
{
  int *p=(int *)a;
  int *q=(int *)b;

  if(*p<*q)
    return 1;
  else
    return 0;

}


