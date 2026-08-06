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
    unordered_set<int>todelete;
    vector<TreeNode*>out;
    void solve(TreeNode*root,bool prevdeleted){
        if(root==nullptr){
            return;
        }
        TreeNode*l=root->left;
        TreeNode*r=root->right;
        if(l!=nullptr&&todelete.find(l->val)!=todelete.end()){
            root->left=nullptr;

        }
        if(r!=nullptr&&todelete.find(r->val)!=todelete.end()){
            root->right=nullptr;
        }
        if(todelete.find(root->val)!=todelete.end()){
            solve(l,true);
            solve(r,true);
        }
        else{
            if(prevdeleted){
                out.push_back(root);
            }
            solve(l,false);
            solve(r,false);
        }

    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &x:to_delete){
            todelete.insert(x);
        }
        solve(root,true);
        return out;

        
    }
};