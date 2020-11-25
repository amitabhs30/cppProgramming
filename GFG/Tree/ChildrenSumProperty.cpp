#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    int data;
    node *right;
    node *left;

    node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }

} *root = NULL;

bool childrenSumP(node *root)
{
    if(root==NULL)
        return true;

    if(root->left==NULL&&root->right==NULL)
        return true;

    int sum=0;
    if(root->left!=NULL)sum+=root->left->data;
    if(root->right!=NULL)sum+=root->right->data;
    return(sum==root->data&&childrenSumP(root->left)&&childrenSumP(root->right));     
}


void createTree()
{
    node *temp = new node(40);
    root = temp;
    root->left = new node(21);
    root->right = new node(19);
    root->left->left = new node(11);
    root->left->right = new node(10);
    root->right->left=new node(17);
    root->right->right=new node(2);
    root->right->right->left=new node(2);
}

int main()
{
    createTree();
    if(childrenSumP(root))
        cout<<"Tree does follow children sum Property";
    else
        cout<<"Not follows";
    return 0;
}
