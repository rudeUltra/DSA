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
    
    bool validBst(TreeNode*root,long long left,long long right){
        if(root==NULL){
            return true; //gotemm
        }
        
        if(root->val<=left || root->val>=right){
            //Ayyo
            return false;
        }
        
        return validBst(root->left,left,root->val) && validBst(root->right,root->val,right);
    }
    
    
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return validBst(root,LONG_MIN,LONG_MAX);
    }
};