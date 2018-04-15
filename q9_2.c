#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{
    int arr[]={2,3,4,5,3};
    int res[4][4]={0};
    int cost=0;
    for(int l=2;l<4;l++)
    {
        for(int i=0;i<3;i++)
        {
            int j=i+l;
            res[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++)
            {
                cost=res[i][k]+res[k][j]+arr[i]*arr[k]*arr[j];
                if(cost<res[i][j])
                {
                    res[i][j]=cost;
                }
            }
        }
    }
    printf("the minimum multiplications required is %d:",res[0][3]);
}