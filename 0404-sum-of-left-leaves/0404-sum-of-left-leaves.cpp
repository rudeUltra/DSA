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
    
    void f(TreeNode*root,bool left,int &count){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL && left){
            count=count+root->val;
            return; //left leaf
        }
        f(root->left,true,count);
        f(root->right,false,count);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int count=0;
        f(root,false,count);
        return count;
    }
};