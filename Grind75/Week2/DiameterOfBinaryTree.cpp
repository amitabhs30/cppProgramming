//Definition for a binary tree node.
#include<algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution{
    public:
        int res = 0;
        int dfs(TreeNode* root){
            if(root == nullptr)
                return 0;
            int l = dfs(root->left);
            int r = dfs(root->right);
            res = max(res,r+l);
            return 1+max(l,r);
        }
        int diameterOfBinaryTree(TreeNode* root){
            return dfs(root);
        }
};
