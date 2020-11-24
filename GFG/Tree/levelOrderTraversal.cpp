#include <iostream>
#include <algorithm>

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

} *Mroot = NULL;


void createTree()
{
    node *temp = new node(10);
    Mroot = temp;
    Mroot->left = new node(20);
    Mroot->right = new node(30);
    Mroot->left->left = new node(40);
    Mroot->left->right = new node(50);
    Mroot->right->left = new node(60);
    Mroot->right->right = new node(70);
    Mroot->right->left->left = new node(80);
}

int main()
{
    createTree();
    return 0;
}