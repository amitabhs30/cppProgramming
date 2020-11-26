#include<iostream>
#include<algorithm>
#include<vector>

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

int preIndex=0;
node* convert(vector<int>pre,vector<int>in,int is,int ie)
{
    if(is>ie)return NULL;

    node *root=new node(pre[preIndex++]);
    int inIndex;
    for(int i=is;i<=ie;i++)
    {
        if(root->data==in[i])
        {
            inIndex=i;
            break;
        }
    }
    root->left=convert(pre,in,is,inIndex-1);
    root->right=convert(pre,in,inIndex+1,ie);
    return root;
}

void inorderTraversal(node *root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the tree";
    cin>>n;
    vector<int>pre(n);
    vector<int>in(n);
    cout<<"Enter the preorder of tree";
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    cout<<"Enter the inorder of the tree";
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    node *root=convert(pre,in,0,n-1);
    inorderTraversal(root);
    return 0;
}