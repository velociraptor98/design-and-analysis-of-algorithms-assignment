#include<stdio.h>
 
void DFS(int);
int **g,*visited,n;
 
void main()
{
    //ONLY FOR UNWEIGHTED GRAPH
    int i,j;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    g=(int**)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        g[i]=(int*)calloc(n,sizeof(int));
    }
    visited=(int*)calloc(n,sizeof(int));
    printf("\nEnter adjecency matrix of the graph:");
    for(i=0;i<n;i++)
       for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);
   for(i=0;i<n;i++)
        visited[i]=0;
    int src;
    printf("enter the src vertex:");
    char dump;
    scanf("%c",&dump);
    scanf("%d",&src);
    DFS(src);
}
 
void DFS(int i)
{
    int j;
    printf("\n%d",i);
    visited[i]=1;
    for(j=0;j<n;j++)
       if(!visited[j]&&g[i][j]==1)
            DFS(j);
}