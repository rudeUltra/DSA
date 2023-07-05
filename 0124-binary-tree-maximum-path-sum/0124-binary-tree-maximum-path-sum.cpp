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

    int f(TreeNode *root,int &ans){
        if(root==NULL){
            return 0;
        }
        int left=max(0,f(root->left,ans));
        int right=max(0,f(root->right,ans)); // 0 to avoid taking negative paths hm

        ans=max(ans,left+right+root->val);
        //no point of taking a negative paths even if all nodes are negative max will be just the root val return it siu

        return max(left,right)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        //path problem so again obvs think of arc type hm
        //interesting question modify the max depth question only hmmm noice
        //think of the arc we can only take left or right max of any
        //so depth modification + extra parameter hm
        int ans=INT_MIN;
        f(root,ans);
        return ans;
    }
};