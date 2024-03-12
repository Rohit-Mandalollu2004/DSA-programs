#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player
{
  char *name;
  int age;
  int test;
  double avg;
};
void readplayer(struct player *p, int n);
void displayplayer(struct player *p, int n);

int cmpname(struct player *a, struct player *b);
void selectionSort(struct player *p, int n, int (*cmp)(struct player *a, struct player *b));

int main()
{
  struct player *p;

  int n;
  printf("enter n:");
  scanf("%d", &n);

  p=(struct player*)malloc(n*sizeof(struct player));
  readplayer(p, n);

  selectionSort(p, n, cmpname);
  printf("afeter sorting\n");
  displayplayer(p, n);

  free(p);
  return 0;
}
void readplayer(struct player *p, int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
      char str[20];
    printf("\nenter name:\n");
    scanf("%s", str);
    p[i].name = (char *)malloc(strlen(str) + 1);
    strcpy(p[i].name, str);

    printf("enter age:\n");
    scanf("%d", &p[i].age);

    printf("enter test matches played:\n");
    scanf("%d", &p[i].test);

    printf("eneter avg of a player:\n");
    scanf("%lf", &p[i].avg);
  }
}

void displayplayer(struct player *p, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("\nname:%s\n", p[i].name);

    printf("age:%d\n", p[i].age);

    printf("test:%d\n", p[i].test);

    printf("avg:%lf\n", p[i].avg);
  }
}
int cmpname(struct player *a, struct player *b)
{

  int c=strcasecmp(a->name, b->name);
  if(c==-1)
     return 1;

  else
    return 0;

}
void selectionSort(struct player *p, int n, int (*cmp)(struct player *a, struct player *b))
{
  int i, j, max;
  struct player temp;

  for (i = 0; i < n - 1; i++)
  {
    max = i;
    for (j = i + 1; j < n; j++)
    {
      if ((*cmp)(&p[j], &p[max]))
        max = j;
    }
    if (max != i)
    {
     temp=p[i];
     p[i]=p[max];
     p[max]=temp;
    }
  }
}
