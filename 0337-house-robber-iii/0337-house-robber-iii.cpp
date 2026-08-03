/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int>solve(TreeNode*root,int &result){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int> left=solve(root->left,result);
        pair<int,int> right=solve(root->right,result);
        int takeme=root->val+left.second+right.second;
        int nottake=max(left.second,left.first)+max(right.second,right.first);
        result=max(takeme,nottake);
        return {takeme,nottake};
    }
    int rob(TreeNode* root) {
        int result=0;
        solve(root,result);
        return result;
        
    }
};