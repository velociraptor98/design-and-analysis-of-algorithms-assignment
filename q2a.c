#include <stdio.h>
#include <stdlib.h>
struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct Node
{
    int data;
    struct Node* next;
};
struct Node *front,*rear = NULL;

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int v;
    struct AdjList* array;

};

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* new = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    new->dest = dest;
    new->next = NULL;

    return new;
}


struct Graph* createGraph(int v)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

    int i;
    for(i=0;i<v;i++)
        graph->array[i].head = NULL;

    return graph;

}

void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for(v=0; v < graph->v;v++)
    {
        struct AdjListNode* crawl = graph->array[v].head;
        printf("Adjacency list of vertex %d\n%d",v,v);
        while(crawl)
        {
            printf("-> %d",crawl->dest);
            crawl = crawl->next;
        }
        printf("\n");
    }
}

int main()
{
    int v;
    printf("enter the number of vertices in the graph:");
    scanf("%d",&v);
    struct Graph* graph = createGraph(v);
    printf("press 1 to add an edge \n 2 to print the graph\n3 to exit\n");
    int choice;
    scanf("%d",&choice);
    do{
        if(choice==1)
        {
            int src,dest;
            printf("enter the source vertex:");
            scanf("%d",&src);
            printf("enter the destination vertex:");
            scanf("%d",&dest);
            addEdge(graph,src,dest);
        }
        else if(choice==2)
        {
            printGraph(graph);
        }
        scanf("%d",&choice);
    }while(choice!=3);
}
