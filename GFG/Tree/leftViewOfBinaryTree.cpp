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

int maxLevel=0;
void printLeftView(node *root,int level)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        if(maxLevel<level)
        {
            cout<<root->data<<" ";
            maxLevel=level;
        }
        printLeftView(root->left,level+1);
        printLeftView(root->right,level+1);
    }
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
    printLeftView(root,1);
    return 0;
}


