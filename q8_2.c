#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lcs(char *s1,char *s2,int m,int n)
{
    int l[100][100];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            {
                l[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                l[i][j]=l[i-1][j-1]+1;
            }
            else{
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }
    return l[m][n];
}
int main()
{
    char *s1=(char*)malloc(100*sizeof(char));
    char *s2=(char*)malloc(100*sizeof(char));
    gets(s1);
    gets(s2);
    int m=strlen(s1);
    int n=strlen(s2);
    int result=lcs(s1,s2,m,n);
    printf("the longest common subsequence is : %d",result);
}