#include <stdio.h>
#include <stdlib.h>
int main()
{
printf("enter the max number of nodes of the grapn\n");
int n;
scanf("%d",&n);
int ** arr=(int**)malloc(n*sizeof(int));
for(int i=0;i<n;i++)
{
    arr[i]=(int*)malloc(n*sizeof(int));
}
for(int i=0;i<n;i++)
{
    int choice;
    for(int j=0;j<n;j++)
    {
        printf("Is node %d connected to node %d :\n",i,j);
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("enter the weight between the 2 nodes: ");
            scanf("%d",&arr[i][j]);
        }
        else
        arr[i][j]=0;
    }
}
printf("the final adjacency matrix is :\n");
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",arr[i][j]);
    }
    printf("\n");
}
}