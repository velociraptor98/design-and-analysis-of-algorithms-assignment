#include <stdio.h>
#include <stdlib.h>

int main()
{
 int n;
 int **orig;
 printf("enter the size of the graph:");
 scanf("%d",&n); 
 orig=(int**)calloc(n,sizeof(int));
int **trans;
 trans=(int**)calloc(n,sizeof(int));
 for(int i=0;i<n;i++)
 {
     orig[i]=(int*)calloc(n,sizeof(int));
     trans[i]=(int*)calloc(n,sizeof(int));
 }
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<n;j++)
     {
         printf("is node %d connected to node %d :",i,j);
         scanf("%d",&orig[i][j]);
     }
 }
 for(int k=0;k<n;k++)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            trans[i][j]=orig[i][j]||(orig[i][k]&&orig[k][j]);
        }
    }
}
printf("the transistive closure of the graph is :\n");
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",trans[i][j]);
    }
    printf("\n");
}
}