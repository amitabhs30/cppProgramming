#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int in=0;

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

void serialize(node *root, vector<int>&arr)
{
    if(root==NULL)
    {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    serialize(root->left,arr);
    serialize(root->right,arr);

}


node *deserialize(vector<int>arr)
{
    if(in==arr.size())return NULL;

    int val=arr[in++];
    if(val==-1)return NULL;

    node * root= new node(val);
    root->left=deserialize(arr);
    root->right=deserialize(arr);
    return root;
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

void PreorderTraversal(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

int main()
{
    createTree();
    vector<int>arr;
    serialize(root,arr);

    for(auto x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;


    node * curr=deserialize(arr);

    PreorderTraversal(curr);


    return 0;
}