/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //left child right chilD les GOOO xD
        if(root==NULL || root->val==p->val || root->val==q->val){
            return root;
        }
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right=lowestCommonAncestor(root->right,p,q);
        
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        
        return root; //siuuu 
        
    }
};