#include <stdio.h>
#include <stdlib.h>
typedef struct item{
int weight;
int value;
float ratio;
}item;
int main()
{
    int w;
    printf("enter the weight of the knapsack:");
    scanf("%d",&w);
    int n;
    printf("enter the number of possible items:");
    scanf("%d",&n);
    item *it=(item*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("enter the weight of the item:");
        scanf("%d",&it[i].weight);
        printf("enter the value of the item:");
        scanf("%d",&it[i].value);
        it[i].ratio=it[i].value/it[i].weight;
    }
    //sort the items accordind to the ratios of value/weight
    for(int i=0;i<n;i++)
    {
        int max=i;
        for(int j=i+1;j<n;j++)
        {
            if(it[j].ratio>it[max].ratio)
            {
                max=j;
            }
        }
        item temp=it[max];
        it[max]=it[i];
        it[i]=temp;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d %d %f\n",it[i].weight,it[i].value,it[i].ratio);
    }
    int currentWeight=0;
    float bagValue=0.0f;
    for(int i=0;i<n;i++)
    {
        if(currentWeight+it[i].weight<=w)
        {
            bagValue+=it[i].value;
            currentWeight+=it[i].weight;
        }
        else
        {
            bagValue+=it[i].value*((float)(w-currentWeight)/it[i].weight);
        }
    }
    printf("the maximum value of the knapsack is :%f",bagValue);
}