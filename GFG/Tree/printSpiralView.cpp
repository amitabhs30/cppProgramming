#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

struct node
{
    int data;
    node *right;
    node *left;

    node(int x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }

} *root = NULL;

void createTree()
{
    node *temp = new node(40);
    root = temp;
    root->left = new node(21);
    root->right = new node(19);
    root->left->left = new node(11);
    root->left->right = new node(10);
    root->right->left=new node(17);
    root->right->right=new node(2);
    root->right->right->left=new node(2);
}

void printSpiralView(node *root)
{
    if (root == NULL)
        return;
    deque<node *> q;
    int level = 1;
    q.push_front(root);
    while (!(q.empty()))
    {
        int count = q.size();
        bool t = level % 2 == 0 ? true : false;
        if (t)
        {
            for (int i = 0; i < count; i++)
            {
                node *temp = q.back();
                q.pop_back();
                cout<<temp->data<<" ";
                if (temp->right != NULL)
                    q.push_front(temp->right);
                if (temp->left != NULL)
                    q.push_front(temp->left);
            }
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                node *temp = q.front();
                q.pop_front();
                cout<<temp->data<<" ";
                if (temp->left != NULL)
                    q.push_back(temp->left);
                if (temp->right != NULL)
                    q.push_back(temp->right);
            }
        }
        level++;
    }
}

int main()
{
    createTree();
    printSpiralView(root);
    return 0;
}
