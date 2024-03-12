#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void display(int arr[] , int n);
int main() {
  int n;
    scanf("%d",&n);
    int arr[n];
    if(n>0)
        display(arr , n);
    else
        printf("Array should not be less than 0.");
    return 0;
}
void display(int arr[] , int n)
{
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    int min=1;
    for(int i=0;i<n;i++)
    {
        if(min>arr[i])
            min=arr[i];
    }
    printf("\nLowest number in array is %d.",min);
}
