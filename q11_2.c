#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n;
    printf("enter the number of vertexes in the graph: ");
    scanf("%d",&n);
    int **orig=(int**)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        orig[i]=(int*)calloc(n,sizeof(int));
    }
    int **trans=(int**)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        trans[i]=(int*)calloc(n,sizeof(int));
    }
    printf("enter the adjacency matrix :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&orig[i][j]);
        }
    }

    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<n;j++ )
        {
            if(orig[i][j])
            {
                trans[i][j]=orig[i][j];
            }
            else{
                trans[i][j]=99999;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                trans[i][j]=min(trans[i][j],trans[i][k]+trans[k][j]);
            }
        }
    }
    printf("the shortest distance matrix is :\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
}