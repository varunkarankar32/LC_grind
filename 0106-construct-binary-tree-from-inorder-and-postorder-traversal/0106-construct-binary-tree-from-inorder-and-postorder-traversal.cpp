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

TreeNode*build(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,unordered_map<int,int>&inordermap){
    if(instart>inend||poststart>postend){
        return nullptr;
    }
    int currentroot=postorder[postend];
    int inorderidx=inordermap[currentroot];
    TreeNode* root=new TreeNode(currentroot);
    int leftsize=inorderidx-instart;

    root->left=build(inorder,instart,inorderidx-1,postorder,poststart,poststart+leftsize-1,inordermap);
    root->right=build(inorder,inorderidx+1,inend,postorder,poststart+leftsize,postend-1,inordermap);
    return root;



}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // postorder given : [9,15,7,20,3]
        // inorder given : [9,3,15,20,7]
        //  postorder -> left | right | root
        // inorder -> left | root | right
        /*     3 
            9    20
               15  7



        */
        unordered_map<int,int>inordermap;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            inordermap[inorder[i]]=i;
        }
        return build(inorder,0,n-1,postorder,0,n-1,inordermap);
        
    }
};