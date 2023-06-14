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
    //all thesae questions are based on the height of the tree type nice post-order siu
    int f(TreeNode*root,int &ans){
        if(root==NULL){
            return 0;
        }
        int x=f(root->left,ans);
        int y=f(root->right,ans);

        ans=max(ans,x+y); //arc

        return 1+max(x,y);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //lets gooo new question xD
        int ans=INT_MIN;
        //path questions so basically make an Arc type figure siu
        f(root,ans);
        return ans;
    }
};