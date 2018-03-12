#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>
struct val{
    int min;
    int max;
};
struct val minmax(int *arr,int n)
{
struct val mm;
mm.min=arr[0];
mm.max=arr[0];
for(int i=1;i<n;i++)
{
    if(arr[i]>mm.max)
    {
        mm.max=arr[i];
    }
    else if(arr[i]<mm.min)
    {
        mm.min=arr[i];
    }
}
return mm;
}
struct val dminmax(int *arr,int start ,int end)
{
struct val mm,mml,mmr;
if(start==end)
{
mm.min=arr[start];
mm.max=arr[start];
return mm;
}
if(end=start+1)
{
    if(arr[start]>arr[end])
    {
        mm.max=arr[start];
        mm.min=arr[end];
    }
    else{
        mm.max=arr[end];
        mm.min=arr[start];
    }
    return mm;
}
int mid=floor((start+end)/2);
mml=dminmax(arr,start,mid);
mmr=dminmax(arr,mid+1,end);
if(mml.min<mmr.min)
{
    mm.min=mml.min;
}
else{
    mm.min=mmr.min;
}
if(mml.max>mmr.max)
{
    mm.max=mml.max;
}
else
{
    mm.max=mmr.max;
}
return mm;
}


int main()
{
srand(time(0));
int n;
printf("enter the size of the array: ");
scanf("%d",&n);
int *arr=(int)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
{
    arr[i]=rand()%INT_MAX;
}
time_t s,e,s1,e1;
s=clock();
struct val one=minmax(arr,n);
printf("the max :%d \n the min :%d\n",one.max,one.min);
e=clock();
s1=clock();
struct val two=dminmax(arr,0,n-1);
printf("the max :%d \n the min :%d\n",two.max,two.min);
e1=clock();
printf("the time for iterative method %lf\n",((double)(e-s))/CLOCKS_PER_SEC);
printf("the time for divide and conquer method %lf\n",((double)(e1-s1))/CLOCKS_PER_SEC);
}