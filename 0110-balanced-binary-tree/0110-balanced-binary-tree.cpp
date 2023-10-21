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

    int f(TreeNode *root,bool &ans){
        if(root==NULL){
            return 0;
        }
        //max depth code
        int x=f(root->left,ans);
        int y=f(root->right,ans);

        if(abs(x-y)>1){
            ans=false;
        }

        return 1+max(x,y);
    }
    bool isBalanced(TreeNode* root) {
        //post-order plus and operator i guess siu
        bool ans=true;
        f(root,ans);
        return ans;
    }
};