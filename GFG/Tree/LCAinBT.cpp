#include <iostream>
#include <algorithm>
#include <vector>

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
    node *temp = new node(10);
    root = temp;
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);
    root->right->left->left = new node(80);
}

bool findPath(int n, node *root, vector<node *> &p)
{
    if (root == NULL)
        return false;
    p.push_back(root);
    if (root->data == n)
        return true;
    if (findPath(n, root->left, p) || findPath(n, root->right, p))
        return true;
    p.pop_back();
    return false;
}

node *findLCA(int n1, int n2, node *root)
{
    vector<node *> p1;
    vector<node *> p2;
    if (root == NULL)
        return NULL;

    if (findPath(n1, root, p1) == false || findPath(n2, root, p2) == false)
        return NULL;

    if (p1[p1.size() - 1] == p2[p2.size() - 1])
        return p1[p1.size() - 1];

    for (int i = 0; i < p1.size() && i < p2.size(); i++)
    {
        if (i + 1 == p1.size())
            return p1[i];
        if (i + 1 == p2.size())
            return p2[i];
        if (p1[i + 1] != p2[i + 1])
            return p1[i];
    }
    return NULL;
}

int main()
{
    createTree();
    int n1, n2;
    cout << "Enter the first Data";
    cin >> n1;
    cout << "Enter the second Data";
    cin >> n2;

    node *LCA = findLCA(n1, n2, root);
    cout << LCA->data << " ";
    return 0;
}