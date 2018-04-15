#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void longPreSuf(int *lps,char *s,int len)
{
lps[0]=0;
int i,j;
j=0;
for(i=1;i<len;)
{
if(s[i]==s[j])
{
    lps[i]=j+1;
    ++i;
    ++j;
}
else
{
    if(j==0)
    {
        lps[i]=0;
        ++i;
    }
    else {
        j=lps[j-1];
    }
}
}
}

int main()
{
char s[100];
printf("enter the pattern: ");
gets(s);
printf("enter the string to search :");
char str[100];
gets(str);
int len2=strlen(str);
int len=strlen(s);
int *lps=(int*)calloc(len,sizeof(int));
longPreSuf(lps,s,len);
int i,j;
i=j=0;
while(i<len2||j<len)
{
    if(s[j]==str[i])
    {
        ++i;
        ++j;
    }
    else
    {
        if(j==0)
        {
            ++i;
        }
        else
        {
            j=lps[j-1];
        }
    }
    if(j==len)
    {
        printf("found at %d\n",i-len);
    }
}
}
