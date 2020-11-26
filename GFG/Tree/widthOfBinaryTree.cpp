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

int findWidth(node *root)
{
    if(root==NULL) return 0;
    queue<node *>q;
    int maxCount=1;
    q.push(root);
    while(!(q.empty()))
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            node *t=q.front();
            q.pop();
            if(t->left!=NULL)q.push(t->left);
            if(t->right!=NULL)q.push(t->right);
        }
        maxCount=max(maxCount,(int)q.size());
    }
    return maxCount;
}

void createTree()
{
    node *temp= new node(10);
    root=temp;
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(60);
    root->right->right=new node(70);
    root->right->left->left=new node (80);
}


int main()
{
    createTree();
    cout<<findWidth(root)<<" ";
    return 0;
}