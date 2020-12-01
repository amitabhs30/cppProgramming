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

int findSize(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    node* curr=root;
    int lh,rh;
    while(curr!=NULL)
    {
        curr=curr->left;
        lh++;
    }
    curr=root;
    while(curr!=NULL)
    {
        curr=curr->right;
        rh++;
    }
    if(rh==lh)return pow(2,lh)-1;
    return 1+findSize(root->left)+findSize(root->right);
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
    cout<<findSize(root)<<" "<<endl;
    return 0;
}