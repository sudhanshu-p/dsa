#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

};
typedef struct Node tree;

tree* create_node();
void InOrder_Traversal(tree* root);
tree* predecessor(tree* root);
tree* delete_node(tree* root, int val);
int height(tree* root);
void current_level(tree* root, int height);

tree* insert(tree* root,int val)
{
    if(root==NULL)
    {
        tree* root= (tree*)malloc(sizeof(tree));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
        return root;
        
    }
    else
    {
        if (val < (root->data))
           root->left=insert(root->left,val);
        else 
        root->right=insert(root->right,val);
    }
    return root;
}

void InOrder_Traversal(tree* root)
{
    if(root==NULL)
    return;

    InOrder_Traversal(root->left);
    printf("%d  ",root->data);
    InOrder_Traversal(root->right);
    
}
void PreOrder_Traversal(tree* root)
{
    if(root==NULL)
    return;

    printf("%d  ",root->data);
    PreOrder_Traversal(root->left);
    PreOrder_Traversal(root->right);
    
}
void PostOrder_Traversal(tree* root)
{
    if(root==NULL)
    return;

    PostOrder_Traversal(root->left);
    
    PostOrder_Traversal(root->right);
    printf("%d  ",root->data);
    
}
void LevelOrder(tree * root) 
{
  int h = height(root);
  int i;
  for (i = 0; i <= h; i++)
    current_level(root, i);
}
void current_level(tree* root, int height)
{
   if(root==NULL)
   return;

   if(height==0)
   printf("%d ",root->data);

   else
   {
       current_level(root->left,height-1);
       current_level(root->right,height-1);
   }
}

tree* predecessor(tree* root)
{
    tree* ptr=root;
    while(root!=NULL && root->right !=NULL)
    {
        root=root->right;
    }
    return root;

}
tree* delete_node(tree* root, int val)
{
    if(root==NULL)
    {
        printf("Given data not found in the tree\n");
        return root;
    }
    else if(root->data >val)
    {
        root->left=delete_node(root->left,val);
    }
    else if(root->data<val)
    {
        root->right=delete_node(root->right,val);
    }
    else 
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        if(root->right==NULL)
        {
            tree* temp =root->left;
            free(root);
            return temp;
        }
        if(root->left==NULL)
        {
            tree* temp =root->right;
            free(root);
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL)
        {
            tree* temp=predecessor(root->left);
            root->data=temp->data;
            root->left=delete_node(root->left,temp->data);
            return root;
        }
    }
}

int height(tree* root)
{
    if(root==NULL)
    return -1;

    if(root->left==NULL && root->left==NULL)
    return 0;

    int lh=height(root->left);
    int rl=height(root->right);

    if(lh>rl)
    return lh+1;
    else
    return rl+1;

}

int leaf_node(tree* root)
{
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    {
        printf("%d, ",root->data);
    return 1;
    }

    return leaf_node(root->left)+ leaf_node(root->right);
}

int parent_node(tree* root)
{
    if(root==NULL)
    return 0;

    if(root->left==NULL && root->right==NULL)
    return 0;

    if(root->left!=NULL || root->right!=NULL)
    {
        printf("%d, ",root->data);
    }

    return parent_node(root->left)+parent_node(root->right)+1;
}
int search(tree* root,int val)
{
    if(root==NULL)
    return 0;

    if(root->data==val)
    return 1;
    int i;

    if(root->data<val)
     i=search(root->right,val);
    else
    i=search(root->left,val);

    return i;

}

int main()
{
    int n,val,ch, l=1,p,lf;
    tree* root=NULL;
    printf("Enter the number of element in Tree: ");
    scanf("%d",&n);
    printf("Enter the elements:\n");

    for(int i=0; i<n; i++)
    {
    scanf("%d",&val);
    root= insert(root,val);
    }
     InOrder_Traversal(root);
     printf("\n");
   
   while(l)
   {
       printf("\n**Main Menu**\n");
       printf("1)Insert\n2)Delete\n3)Inorder Traversal\n4)Preorder Traversal\n5)Postorder Traversal\n6)Level order\n7)Height\n8)Parent and Leaf Node\n9)To locate a Key\n10)Exit\nYour choice: ");
       scanf("%d",&ch);

       switch(ch)
       {
           case 1:printf("Enter a data to be inserted: ");
                  scanf("%d",&val);
                  root= insert(root,val);
                  break;

           case 2:printf("Enter a data to be deleted: ");
                  scanf("%d",&val);
                  root= delete_node(root,val);
                  break;

           case 3:printf("You opted for Inorder Traversal\n"); 
                  InOrder_Traversal(root);
                  printf("\n");
                  break;

           case 4:printf("You opted for Preorder Traversal\n"); 
                  PreOrder_Traversal(root);
                  printf("\n");
                  break;

           case 5:printf("You opted for Postorder Traversal\n"); 
                  PostOrder_Traversal(root);
                  printf("\n");
                  break;
           case 6: printf("Level order traversal\n");
                  LevelOrder(root);
                  break;

           case 7:printf("Height of the tree is %d",height(root));
                  break;
            
           case 8:printf("Parent node are--> ");
                  p=parent_node(root);
                  printf("Total Parent node are %d \n",p);
                  printf("Leaf Node are--> ");
                  lf=leaf_node(root);
                  printf("Total leaf node are %d \n",lf);
                  break;

           case 9:printf("Enter a data to be searched\n");
                  scanf("%d",&val);
                  if(search(root,val))
                  printf("%d is present in Tree\n",val);
                  else
                  printf("%d is Not present in Tree\n",val);
                  break;

           case 10: l=0; break;
          
          default: printf("Enter a valid statement\n");
       }
       
   }

   
    
}

tree* create_node()
{
    tree* root=(tree*)malloc(sizeof(tree));

    if(root==NULL)
    {
        return NULL;
    }
    else 
    {
        printf("Node created\n");
        return root;
    }
}
