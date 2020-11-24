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


void printAtK(node *root,int k)
{
    if(root==NULL)
    return;
    if(k==0)
    cout<<root->data<<" ";
    else
    printAtK(root->left,k-1);
    printAtK(root->right,k-1);
}


void createTree()
{
    node *temp= new node(10);
    root=temp;
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node (50);
    root->right->left=new node(60);
    root->right->right=new node(70);
    root->right->left->left=new node (80);
}


int main()
{
    createTree();
    printAtK(root,0);
    return 0;
}