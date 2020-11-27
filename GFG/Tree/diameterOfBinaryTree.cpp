#include <iostream>
#include <algorithm>
#include <unordered_map>

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

unordered_map<node *, int> heights;

void PreprocessHeight(node *root)
{
   if (root == NULL)
        heights[root] = 0;
    else
    {
    PreprocessHeight(root->left);
    PreprocessHeight(root->right);
    heights[root]=max(heights[root->right],heights[root->left])+1;
    }
}

int height(node* root)
{
    if(root==NULL)return 0;
    else return max(height(root->left),height(root->right))+1;
}

int findDiameter(node *root)    //O(n^2) Time complexity and O(1) space complexity.
{
    if (root == NULL)
        return 0;

    int v1 = height(root->left) + height(root->right) + 1;
    int v2 = findDiameter(root->left);
    int v3 = findDiameter(root->right);
    return (max(v1, max(v2, v3)));
}



void createTree()
{
    node *temp = new node(10);
    root = temp;
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->left->right->left=new node(90);
    root->right->left = new node(60);
    root->right->right = new node(70);
    root->right->right->left=new node(100);
}

int findDiameterE(node *root)   // O(n) Time complexity with O(n) auxilary space
{
    if (root == NULL)
        return 0;

    int v1=heights[root->left]+heights[root->right]+1;
    int v2=findDiameterE(root->left);
    int v3=findDiameterE(root->right);

    return max(v1,max(v2,v3));
}
int res=0;
int findDiameterVE(node *root)  //O(n) Time complexity with O(1) auxilary space.
{
    if(root==NULL)return 0;

    int lh=findDiameterVE(root->left);
    int rh=findDiameterVE(root->right);
    res=max(res,lh+rh+1);
    return max(lh,rh)+1;
}

int main()
{
     createTree();
    // PreprocessHeight(root);
    // for(auto x:heights)
    // {
    //     if(x.first!=NULL)
    //     cout<<x.first->data<<" "<<x.second<<endl;
    // }
    // cout << findDiameterE(root) << " ";
    int x=findDiameterVE(root);
    cout<<res<<endl;
    return 0;
}