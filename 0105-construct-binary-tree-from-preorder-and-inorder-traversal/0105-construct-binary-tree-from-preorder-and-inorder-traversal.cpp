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
    unordered_map<int,int>inordermap;
    TreeNode* build(vector<int>&preorder,int pstart,int pend,vector<int>&inorder,int instart,int inend){
        if(pstart>pend||instart>inend){
            return nullptr;
        }
        int inorderidx=inordermap[preorder[pstart]];
        int leftsize=inorderidx-instart;
        TreeNode*root= new TreeNode(inorder[inorderidx]);
        root->left=build(preorder,pstart+1,pstart+leftsize,inorder,instart,inorderidx-1);
        root->right=build(preorder,pstart+leftsize+1,pend,inorder,inorderidx+1,inend);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        for(int i=0;i<n;i++){
            inordermap[inorder[i]]=i;
        }
        return build(preorder,0,n-1,inorder,0,n-1);
        

        
    }
};