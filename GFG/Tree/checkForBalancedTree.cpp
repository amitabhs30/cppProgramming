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


int height(node *root){

    if(root==NULL)
    {
        return 0;
    }
    return(max(height(root->right),height(root->left))+1);
}

bool isBalanced(node* root)
{
    if(root==NULL)return true;
    int lh=height(root->left);
    int rh=height(root->right);
    return(abs(lh-rh)<=1&&isBalanced(root->right)&&isBalanced(root->left));
}

int isBalancedE(node* root)
{
    if(root==NULL)return 0;

    int lh=isBalancedE(root->left);

    if(lh==-1)return -1;

    int rh=isBalancedE(root->right);

    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;

    else return(max(lh,rh)+1);
}

void createTree()
{
    node *temp = new node(40);
    root = temp;
    root->left = new node(21);
    root->right = new node(19);
    root->right->left=new node(17);
    root->right->right=new node(2);
    root->right->right->left=new node(2);
}


int main()
{
    createTree();
    // if(isBalanced(root))cout<<"The tree is balanced";
    // else cout<<"Not balanced";

    if(!(isBalancedE(root)==-1)) cout<<"The tree is balanced";
    else cout<<"Not balanced";
    
    return 0;
}