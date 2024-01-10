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
  
    void dfs(TreeNode *root,vector<int>&tree){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            tree.push_back(root->val);
        }
        dfs(root->left,tree);
        dfs(root->right,tree);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
          vector<int>tree1;
    vector<int>tree2;
        dfs(root1,tree1);
        dfs(root2,tree2);
        
        return tree1==tree2;
    }
};