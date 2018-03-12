#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
void merge(int *arr,int start,int mid,int end)
{
    int p=start;
    int q=mid+1;
    int *a=(int)calloc(end-start+1,sizeof(int));
    int k=0;
    for(int i=start;i<=end;i++)
    {
        if(p>mid)
        {
            a[k++]=arr[q++];
        }
        else if(q>end)
        {
            a[k++]=arr[p++];
        }
        else if(arr[p]<arr[q])
        {
            a[k++]=arr[p++];
        }
        else if(arr[p]>arr[q])
        {
            a[k++]=arr[q++];
        }
    }
    for(int i=0;i<k;i++)
{
    arr[start++]=a[i];
}
}

void merge_sort(int *arr,int start,int end)
{
if(start<end)
{
    int mid=(start+end)/2;
    merge_sort(arr,start,mid);
    merge_sort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
}
void bubble(int *arr,int n)
{
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
}
int main()
{
    srand(time(0));
    int n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    int *arr=(int)calloc(n,sizeof(int));
    int *brr=(int)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%INT_MAX;
        brr[i]=arr[i];
    }
    time_t s1,e1,s2,e2;
    s1=clock();
    merge_sort(arr,0,n-1);
    e1=clock();
    s2=clock();
    bubble(brr,n);
    e2=clock();
    printf("the time for mergesort: %lf\n",((double)(e1-s1))/CLOCKS_PER_SEC);
     printf("the time for bubblesort: %lf",((double)(e2-s2))/CLOCKS_PER_SEC);
}