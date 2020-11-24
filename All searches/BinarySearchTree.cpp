#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void insertElement(struct node*, int);
void showElements();
void traverse(struct node*);

struct node {
    node  *lchild;
    node *rchild;
    int data;
};

struct node *root=NULL;
void addElementInBST()
{
    int element;
    cout<<"Enter the element you want to insert in BST"<<endl;
    cin>>element;
    if (root==NULL)
    {
        struct node *temp=new struct node;
        temp->lchild=NULL;
        temp->rchild=NULL;
        temp->data=element;
        root=temp;
    }
    else
    {
        struct node *temp=new struct node;
        temp=root;

        insertElement(temp, element);
    }

}

void insertElement(struct node *node, int element) {

    if (element<node->data)
    {
        if (node->lchild==NULL)
        {
            struct node *temp=new struct node;
            temp->lchild=NULL;
            temp->rchild=NULL;
            temp->data=element;
            node->lchild=temp;
        }
        else
        {
            insertElement(node->lchild, element);
        }
    }
    else
    {
        if (node->rchild==NULL)
        {
            struct node *temp=new struct node;
            temp->lchild=NULL;
            temp->rchild=NULL;
            temp->data=element;
            node->rchild=temp;
        }
        else
        {
            insertElement(node->rchild, element);
        }

    }


}
int main() {
    int choice;
    while (1)
    {
        cout<<"Enter what you want to do from the menu."<<endl;
        cout<<"press 1 to enter element in BST"<<endl;
        cout<<"press 2 to show the elements of the BST"<<endl;
        cout<<"press 0 to exit the program"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:addElementInBST();
            break;
        case 2:showElements();
            break;
        case 0:exit(0);
            break;
        default:cout<<"wrong choice!";
            break;
        }
    }

    return 0;
}
void showElements() {
    if (root==NULL)
    {
        cout<<"Empty BST";
    }
    else
    {
        struct node *temp=new struct node;
        temp=root;
        traverse(temp);
    }

}
void traverse(struct node * temp) {

    if (temp->lchild!=NULL)
    {
        traverse(temp->lchild);
    }
    cout<<"\n"<<temp->data<<endl;
    if (temp->rchild!=NULL)
    {
        traverse(temp->rchild);
    }
}

