#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct item{
    int weight;
    int value;
}item;
int main()
{
    int kWeight;
    printf("enter the weight of the knapsack:");
    scanf("%d",&kWeight);
    int n;
    printf("enter the number of items :");
    scanf("%d",&n);
    item *it=(item*)calloc(n,sizeof(item));
    for(int i=0;i<n;i++)
    {
        printf("enter the weight of the item :");
        scanf("%d",&it[i].weight);
        printf("enter the value of the item :");
        scanf("%d",&it[i].value);
    }
    int values[100][100];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=kWeight;j++)
        {
            if(i==0||j==0)
            {
                values[i][j]=0;
            }
            else if(it[i-1].weight<=j)
            {
                
                values[i][j]= max(it[i-1].value+values[i-1][j-it[i-1].weight],values[i-1][j]);
            }
            else
            {
                values[i][j]=values[i-1][j];
            }
        }
    }
    printf("the value of item in the knapsack is :%d",values[n][kWeight]);
}