#include <stdio.h>
#include <stdlib.h>

void insert(int num,int *heap,int heapSize,int *sizeTrack)
{
    if(*sizeTrack==heapSize)
    {
        printf("the heap is full\n");
        return;
    }
    else{
        heap[*sizeTrack]=num;
        int pos=*sizeTrack;
        while(pos>0)
        {
            int parent=pos/2;
            if(heap[parent]<=heap[pos])
            {
                break;
            }
            else{
                int t=heap[parent];
                heap[parent]=heap[pos];
                heap[pos]=t;
                pos=parent;
            }
        }
        ++(*sizeTrack);
    }
}
void del(int *heap,int heapSize,int *sizeTrack)
{
    if(*sizeTrack==0)
    {
        printf("the heap is empty\n");
        return;
    }
    else{
    printf("The minimum value that is deleted is :%d\n",heap[0]);
    heap[0]=heap[*sizeTrack-1];
    int pos=0;
    while(pos<*sizeTrack/2)
    {
       int left=pos*2+1;
       int right=pos*2+2;
       if(right<*sizeTrack&&heap[right]<heap[left])
       {
           if(heap[pos]<=heap[right])
           {
               break;
           }
           else{
               int t=heap[pos];
               heap[pos]=heap[right];
               heap[right]=t;
               pos=right;
           }
       }
       else{
           if(heap[pos]>=heap[left])
           {
               int t=heap[pos];
               heap[pos]=heap[left];
               heap[left]=t;
               pos=left;
           }
           else{
               break;
           }
       }
    }
    --(*sizeTrack);
    }
}
void find(int num,int *heap,int heapSize)
{
    for(int i=0;i<heapSize;i++)
    {
        if(heap[i]==num)
        {
            printf("Number found\n");
            return;
        }
    }
    printf("Number not found\n");
}
int main()
{
    printf("enter the size of the heap:");
    int heapSize;
    scanf("%d",&heapSize);
    int *heap=(int*)calloc(heapSize,sizeof(int));
    int sizeTrack=0;
    printf("enter 1 to insert :\n enter 2 to delete \n enter 3 to find a value\n enter 4 to exit \n");
    int choice;
    scanf("%d",&choice);
    do{
        if(choice==1)
        {
            printf("enter the value you want to add :");
            int num;
            scanf("%d",&num);
            insert(num,heap,heapSize,&sizeTrack);
        }
        else if(choice==2)
        {
            del(heap,heapSize,&sizeTrack);
        }
        else if(choice==3)
        {
            int num;
            printf("enter the number you want to find in the priority queue:");
            scanf("%d",&num);
            find(num,heap,heapSize);
        }
        printf("reenter your choice :");
        scanf("%d",&choice);
    }while(choice!=4);
}