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
    void dfs(TreeNode*root,int &ans,int k,int &count){
        if(root==NULL){
            return;
        }
        
        dfs(root->left,ans,k,count); //inorder lef node right
        
        count++;
        if(count==k){
            ans=root->val;
            return;
            
        }
        
      
        dfs(root->right,ans,k,count);
    }
    
    
    
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int count=0;
        dfs(root,ans,k,count);
        
        return ans;
        
        
    }
};