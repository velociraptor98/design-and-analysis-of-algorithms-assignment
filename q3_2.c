#include <stdio.h>
#include <stdlib.h>
 struct set{
    char data;
    struct set  *parent;
};
void find(char num,struct set *arr,int n)
{
    int i=0;
    for(;i<n;i++)
    {
        if(arr[i].data==num)
        {
            break;
        }
    }
    printf("the data element %c belongs to the set of %c\n",num,arr[i].parent->data);
}
void uni(struct set *arr)
{
int dest,src;
printf("enter the destination vertex :");
scanf("%d",&dest);
printf("enter the source vertex :");
scanf("%d",&src);
arr[src].parent=&arr[dest];
}
void makeset(struct set *arr,int n)
{
for(int i=0;i<n;i++)
{
    char dummy;
    printf("enter the node data of the first disjoint set:");
    scanf("%c",&arr[i].data);
    scanf("%c",&dummy);
    arr[i].parent=&arr[i];
}
}
int main()
{
    int n;
    char dummy;
    printf("enter the number of elements in the set:");
    scanf("%d",&n);
    scanf("%c",&dummy);
    struct set *arr=(struct set*)calloc(n,sizeof(struct set));
    makeset(arr,n);
    int choice;
    printf("press 1 to do a union operation\n2 to do a find operation\n 3 to exit\n");
    scanf("%d",&choice);
    do{
        if(choice==1)
        {
            uni(arr);
        }
        else if(choice==2)
        {
            printf("enter the number whose set you want to find out :");
            char num;
            scanf("%c",&num);
            find(num,arr,n);
        }
        printf("reenter your choice:");
        scanf("%d",&choice);
        scanf("%c",&dummy);
    }while(choice!=3);
}