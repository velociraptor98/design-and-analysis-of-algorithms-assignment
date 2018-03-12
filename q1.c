#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* insert (struct node* r,int data)
{
    if(r==NULL)
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=data;
        r->left=NULL;
        r->right=NULL;
        return r;
    }
    else
    {
        if(data<(r->data))
        {
            r->left=insert(r->left,data);
        }
        else{
            r->right=insert(r->right,data);
        }
        return r;
    }
}
void preOrder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct node* root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
struct node* mini(struct node* root)
{
    struct node* c=root;
    while(c->left!=NULL)
    {
    c=c->left;
    }
    return c;
}
struct node* del(struct node* root,int dele)
{
if(root==NULL)
{
    printf("the tree is empty\n");
    return root;
}
if(root->data>dele)
{
    root->left=del(root->left,dele);
}
else if(root->data<dele)
{
    root->right=del(root->right,dele);
}
else{
    if(root->right==NULL)
    {
      struct node* temp=root->left;
      free(temp);
      return temp;
    }
    else if(root->left==NULL)
    {
        struct node* temp=root->right;
        free(temp);
        return temp;
    }
        struct node* temp= mini(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }
    return root;
}

int height(struct node* root)
{
    if (root==NULL) 
       return 0;
   else
   {
   
       int lDepth = height(root->left);
       int rDepth = height(root->right);
 
     
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}
int search(struct node*root,int num)
{
    if(num==root->data)
    {
        printf("FOUND\n");
        return 1;
    }
    else if(num>root->data)
    {
        search(root->right,num);
    }
    else{
        search(root->left,num);
    }
    return 0;
}
int main()
{
int choice;
printf("enter the choice you want to make\n1: for add element\n 2: for preOrder \n 3: for inOrder \n 4: for postOrder \5 for deleting a node \n 6: for height\n7 for search\n 8 for exit\n");
scanf("%d",&choice);
struct node* root;
root=NULL;

 do{
     switch(choice)
     {
         case 1: int num;
                printf("enter the number to add \n");
                scanf("%d",&num);
                root=insert(root,num);
                break;
        case 2: preOrder(root);
                break;
        case 3: inOrder(root);
                break;
        case 4: postOrder(root);
                break;
        case 5: int dele;
                printf("enter the value to delete\n");
                scanf("%d",&dele);
                del(root,dele);
                break;
        case 6:int h=height(root);
                printf("The height is: %d\n",h);
                break;
        case 7:int numa;
                printf("enter the number you want to search for:");
                scanf("%d",&numa);
                int a=search(root,numa);
                if(a==0)
                {
                    printf("NOT FOUND");
                }
                else{
                    printf("FOUND");
                }
                break;
     };
        printf("renter your choice:");
        scanf("%d",&choice);
     }
 while(choice!=8);
}

