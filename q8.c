#include<stdio.h>
int pow(int n,int m)
{
 int t;
 if(m==0)
    return 1;
t=pow(n,m/2);
if(m%2==0)
    return t*t;
 else
    return n*t*t;
}
int main()
{
int n,m;
printf("enter the base:");
scanf("%d",&n);
printf("enter the power:");
scanf("%d",&m);
int result=pow(n,m);
printf("the result is :%d",result);
}