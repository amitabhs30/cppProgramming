#include<iostream>
#include<algorithm>
#include<queue>

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
            maxLevel=level;
        }
            cout<<root->data<<" ";
        printLeftView(root->left,level+1);
        printLeftView(root->right,level+1);
    }
}

void printLeftViewIterative(node *root)
{
    queue<node*>q;
    if(root==NULL)
    {
        return;
    }
    q.push(root);

    while(!(q.empty()))
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node* t=q.front();
            q.pop();
            if(i==0)
                cout<<t->data<<" ";
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);       
        }
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
    //printLeftView(root,1);
    printLeftViewIterative(root);
    return 0;
}


