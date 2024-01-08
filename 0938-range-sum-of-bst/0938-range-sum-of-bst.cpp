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
    
    
    void f(TreeNode*root,int low,int high,int &ans){
        if(root==NULL){
            return;
        }
        
        f(root->left,low,high,ans);
        if(root->val>=low && root->val<=high){
            ans+=root->val;
        }
        f(root->right,low,high,ans);
        
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        //BST INORDER SO SORTED SIU
        if(root==NULL){
            return 0;
        }
        
        int ans=0;
        f(root,low,high,ans);
        
        return ans;
        
    }
};