#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
void linear(int *arr,int n,int num)
{
    int flag=0;
    for(int i=0;i<n;i++)
{
    if(num==arr[i])
    {
        printf("Number found at %d\n ",i);
        flag=1;
        break;
    }
}
if(flag==0)
{
    printf("Number not found \n");
}
}
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
        return;
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
int main()
{
srand(time(0));
int n;
printf("enter the size of the array:");
scanf("%d",&n);
int *arr=(int)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
{
    arr[i]=rand()%10000;
}
int num;
printf("enter the number you want to find:");
scanf("%d",&num);
time_t s,e;
s=clock();
linear(arr,n,num);
e=clock();
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
time_t s1,e1;
s1=clock();
biter(arr,num,n-1);
e1=clock();
printf("for linear search the time is:%lf\n ",((double)(e-s))/CLOCKS_PER_SEC);
printf("for binary search the time is:%lf\n ",((double)(e1-s1))/CLOCKS_PER_SEC);
}