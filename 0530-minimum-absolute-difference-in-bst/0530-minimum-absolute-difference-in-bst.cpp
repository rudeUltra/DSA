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
    TreeNode*prev=NULL;
    void dfs(TreeNode*root,int &ans){
        if(root->left){
            dfs(root->left,ans);
        }
        if(prev!=NULL){
            ans=min(ans,abs(prev->val-root->val));
        }
        prev=root;
        
        if(root->right){
            dfs(root->right,ans);
        }
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        //remmeber inorder gives sorted siu left root right
        int ans=INT_MAX;
        
        
        dfs(root,ans);
        
        return ans;
    }
};