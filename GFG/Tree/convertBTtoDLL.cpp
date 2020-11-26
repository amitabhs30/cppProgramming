#include<iostream>

using namespace std;
struct node{
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
}*Mroot;

node * previ;
node* convert(node * root)
{
    if(root==NULL)return root;

    node * head=convert(root->left);
    if(previ==NULL)head=root;
    else
    {
        previ->right=root;
        root->left=previ;
    }
    previ=root;
    convert(root->right);
    return head;
}


void createTree()
{
    Mroot=new node(10);
    Mroot->left=new node(5);
    Mroot->right=new node (20);
    Mroot->right->left=new node(30);
    Mroot->right->right=new node(35);
}

void traverse(node *head)
{
    if(head==NULL)return;
    node *t=head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";  
        t=t->right;    
     }
}

int main()
{
    createTree();

    node *head=convert(Mroot);
    traverse(head);

    return 0;
}