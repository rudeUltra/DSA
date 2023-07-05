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
    void dfs(TreeNode*root,int &ans,int prev){
        if(root==NULL){
            return;
        }
        if(root->val>=prev){
            cout<<root->val<<" ";
            ans++;
        }
        prev=max(prev,root->val);
        
        
        dfs(root->left,ans,prev);
        dfs(root->right,ans,prev);
    }
    
    
    int goodNodes(TreeNode* root) {
        //basically preorder with extra parameters sed
        int ans=0;
        int prev=INT_MIN;
        
        dfs(root,ans,prev);
        return ans;
    }
};