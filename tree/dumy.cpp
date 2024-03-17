#include<iostream>
using namespace std;
/* A tree node structure */
struct node
{
int data;
struct node *left;
struct node *right;
};

int height(struct node *root)
{
if(root==NULL) 
return 0;


int lh=height(root->left);
int rh=height(root->right);

return lh>rh?(lh+1):(rh+1);
}
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
struct node *temp = new struct node;
temp->data = data;
temp->left = NULL;
temp->right = NULL;

return temp;
}
void inorder(struct node *root,int k,int i)
{
if(root==NULL)
return ;

else 
{
inorder(root->left,k,i+1);

if(i==k)
{
printf("%d ",root->data);

}

inorder(root->right,k,i+1);
}
}
/* Driver function to test above functions */
int isBST(node *node,int t)
{ if (node == NULL&&t==0) 
    return 1; 
     
  /* false if left is > than node */
  if (node->left != NULL && node->left->data > node->data) 
    return 0; 
     
  /* false if right is < than node */
  if (node->right != NULL && node->right->data < node->data) 
    return 0; 
   
  /* false if, recursively, the left or right is not a BST */
  if (!isBST(node->left,t-2) || !isBST(node->right,t-2)) 
    return 0; 
     
  /* passing all that, it's a BST */
  return 1; 
}
int main()
{
struct node *root = new struct node;

/* Constructing tree given in the above figure */
root = newNode(3);
root->left = newNode(2);
root->right = newNode(7);
root->left->left = newNode(1);
root->left->right = newNode(4);
root->left->left->left = newNode(11);
root->left->right->left = newNode(14);
root->left->left->right = newNode(12);
root->left->right ->right= newNode(44);
int i;

int ht=height(root);
for(i=1;i<=ht;i++)
{
inorder(root,i,1);
printf("\n");}

cout<<isBST(root,3);

getchar();
return 0;
}

