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
    TreeNode* build(vector<int>&preorder,int prestart,int preend,vector<int>&postorder,int poststart,int postend,unordered_map<int,int>&postordermap){
        if(prestart>preend||poststart>postend){
            return nullptr;
        }
        TreeNode*root=new TreeNode(preorder[prestart]);
        if(prestart==preend){
            return root;
        }
   int leftrootvalue=preorder[prestart+1];
   int postleftboundary=postordermap[leftrootvalue];
   int leftsize= postleftboundary-poststart+1;
   root->left=build(preorder,prestart+1,prestart+leftsize,postorder,poststart,postleftboundary,postordermap);
   root->right=build(preorder,prestart+leftsize+1,preend,postorder,postleftboundary+1,postend-1,postordermap);
   return root;



    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int>postordermap;
        int n=postorder.size();

        for(int i=0;i<n;i++){
            postordermap[postorder[i]]=i;
        }
        return build(preorder,0,n-1,postorder,0,n-1,postordermap);
    
        
        

        
        
    }
};
/*
preorder given : [1,2,4,5,3,6,7]
postorder given : [4,5,2,6,7,3,1]



*/