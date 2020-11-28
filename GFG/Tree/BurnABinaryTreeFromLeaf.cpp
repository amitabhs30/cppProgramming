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
int res=0;
int burn(node *root,int leaf,int &dist){
    if(root==NULL)return 0;

    if(root->data==leaf)
    {
        dist=0;
        return 1;
    }
    int ldist=-1;int rdist=-1;
    int lh=burn(root->left,leaf,ldist);
    int rh=burn(root->right,leaf,rdist);

    if(rdist!=-1)
    {
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    if(ldist!=-1)
    {
        dist=ldist+1;
        res=max(res,dist+rh);
    }
    return max(lh,rh)+1;
}

void createTree()
{
    node *temp= new node(10);
    root=temp;
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(40);
    root->left->right=new node (50);
    root->left->left->left=new node(60);
    root->left->left->left->left=new node(70);
}


int main()
{
    createTree();
    int dist=-1;
    int h=burn(root,50,dist);
    cout<<res<<" Seconds to burn down the tree";


    return 0;
}