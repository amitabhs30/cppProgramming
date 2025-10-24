#include <algorithm>
#include <cstddef>
#include <iostream>
#include<unordered_map>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:


unordered_map<TreeNode*, int>height_map;

    // int find_height(TreeNode* root){
    //     if(root==nullptr){
    //         return 0;
    //     }
    //     if(root->left==nullptr && root->right==nullptr){
    //         height_map.emplace(root,0);
    //         return 0;
    //     }
    //     int left_height = root->left!=nullptr?1+find_height(root->left):0;
    //     int right_height = root->right!=nullptr?1+find_height(root->right):0;
    //     height_map.emplace(root,max(left_height,right_height));
    //     return height_map[root];
    // }

    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr)
    //         return true;
    //     if(height_map.empty())
    //         find_height(root);
    //     bool left_balanced = isBalanced(root->left);
    //     bool right_balanced = isBalanced(root->right);
    //     if(!left_balanced || !right_balanced)
    //         return false;
    //     int right_height = root->right!=nullptr?height_map[root->right]:0;
    //     int left_height = root->left!=nullptr?height_map[root->left]:0;
    //     cout<<right_height;
    //     cout<<'\n'<<left_height;
    //     return abs(right_height-left_height)<=1;
    // }
    bool isBalanced(TreeNode* root){
        if(dfs(root)==-1)return false;
        else return true;
    }

    int dfs(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if (leftHeight==-1 || rightHeight==-1)
            return -1;
        int diff = abs(leftHeight-rightHeight);
        if(diff>1){
            return -1;
        }
        return 1+max(leftHeight,rightHeight);
    }
};
