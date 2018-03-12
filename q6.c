#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>

int part1(int *arr,int start,int end)
{
int pivot=arr[start];
int pele=start+1;
for(int i=start+1;i<=end;i++)
{
    if(arr[i]<pivot)
    {
        int temp=arr[i];
        arr[i]=arr[pele];
        arr[pele]=temp;
        ++pele;
    }
}
int temp=arr[start];
arr[start]=arr[pele-1];
arr[pele-1]=temp;
return pele-1;
}
void q1(int *a,int start,int end)
{
    if(start<end)
    {
        int pind=part1(a,start,end);
        q1(a,start,pind-1);
        q1(a,pind+1,end);
    }
}
int randpart(int *arr,int start,int end )
{
    int random=start+rand()%(end-start+1);
    arr[random]^=arr[start];
    arr[start]^=arr[random];
    arr[random]^=arr[start];
    return part1(arr,start,end);
}
void q2(int *a,int start,int end)
{
    if(start<end)
    {
        int pind=randpart(a,start,end);
        q1(a,start,pind-1);
        q1(a,pind+1,end);
    }
}

int median(int *arr,int start,int end)
{
    int mid=(start+end)/2;
    if(arr[mid]<arr[end])
    {
        int temp=arr[mid];
        arr[mid]=arr[end];
        arr[end]=temp;
    }
    if(arr[start]<arr[mid])
    {
    int temp=arr[start];
    arr[mid]=arr[start];
    arr[start]=temp;    
    }
    if(arr[start]<arr[end])
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
    }
    int temp=arr[mid];
        arr[mid]=arr[end-1];
        arr[end-1]=temp;
        return part1(arr,start,end);
}
void q3(int *a,int start,int end)
{
    if(start<end)
    {
        int pind=median(a,start,end);
        q1(a,start,pind-1);
        q1(a,pind+1,end);
    }
}
int main()
{
    time_t s1,s2,s3,e1,e2,e3;
    int n;
    printf("enter the size of the array:");
    scanf("%d",&n);
    int *arr=(int)calloc(n,sizeof(int));
    int *brr=(int)calloc(n,sizeof(int));
    int *crr=(int)calloc(n,sizeof(int));
    srand(time(0)); 
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%INT_MAX;
        brr[i]=arr[i];
        crr[i]=arr[i];
    }
    s1=clock();
    q1(arr,0,n-1);
    e1=clock();
    s2=clock();
    q2(brr,0,n-1);
    e2=clock();
    s3=clock();
    q3(crr,0,n-1);
    e3=clock();
    printf("The time for quicksort with pivot in begining :%lf\n",((double)(e1-s1))/CLOCKS_PER_SEC);
    printf("The time for quicksort with randomized pivot :%lf\n",((double)(e2-s2))/CLOCKS_PER_SEC);
    printf("The time for quicksort with pivot based on median :%lf\n",((double)(e3-s3))/CLOCKS_PER_SEC);
}