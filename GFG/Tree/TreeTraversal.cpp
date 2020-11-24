#include<iostream>
#include<algorithm>


using namespace std;

struct node{
int data;
node *right;
node *left;

node(int x){
    data=x;
    right=NULL;
    left=NULL;
}

}*root=NULL;



void inorderTraversal(node *root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(node *root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(node *root)
{
    if(root!=NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->data<<" ";
    }
}


int main()
{
    node *temp= new node(10);
    root=temp;
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node (50);
    root->right->left=new node(60);
    root->right->right=new node(70);
    inorderTraversal(root);
    cout<<"\n";
    preorderTraversal(root);
    cout<<"\n";
    postorderTraversal(root);
    return 0;
}