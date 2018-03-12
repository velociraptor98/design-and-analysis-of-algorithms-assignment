#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <limits.h>
void biter(int *arr,int num,int n)
{
int start=0;
int end=n-1;
while(start<end)
{
    int mid=((start+end)/2);
    if(arr[mid]==num)
    {
        printf("number found at %d\n",mid);
        return ;
    }
    else if(num>arr[mid])
    {
        start=mid+1;
    }
    else 
    {
        end=mid-1;
    }
}
printf("number not found\n");
}
void brec(int *arr,int num,int start,int end)
{
   if(start<end)
   {
       int mid=(start+end)/2;
       if(arr[mid]==num)
       {
           printf("number found at position: %d\n",mid);
       }
       else if(num>arr[mid])
       {
           brec(arr,num,mid+1,end);
       }
       else
       {
           brec(arr,num,start,mid-1);
       }
   }
}
int main()
{
    srand(time(0));
    printf("enter the size of the aray:");
    int n;
    scanf("%d",&n);
    int *arr=(int)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
      arr[i]=rand()%INT_MAX;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int num;
    printf("enter the number to search for:");
    scanf("%d",&num);
    clock_t s1,e1,s2,e2;
    double cpu1,cpu2;
    s1=clock();
    biter(arr,num,n);
    e1=clock();
    cpu1=((double)(e1-s1))/CLOCKS_PER_SEC;
    s2=clock();
    brec(arr,num,0,n-1);
    e2=clock();
    cpu2=((double)(e2-s2))/CLOCKS_PER_SEC;
    printf("for iterative %lf\n",cpu1);
    printf("for recursive %lf\n",cpu2);
}