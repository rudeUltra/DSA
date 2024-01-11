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
    
    
    void f(TreeNode*root,int &ans,int mx,int mn){
        if(root==NULL){
            return;
        }
        
        //PreOrder gotemm
         mx=max(mx,root->val);
        mn=min(mn,root->val);
        
        
        ans=max(ans,abs(root->val-mx));
        ans=max(ans,abs(root->val-mn));
        
       
        f(root->left,ans,mx,mn);
        f(root->right,ans,mx,mn);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        //Min ? Max ans can only be from minimum or maximum big brain BC
        int ans=0;
        
        f(root,ans,INT_MIN,INT_MAX);
        
        return ans;
    }
};