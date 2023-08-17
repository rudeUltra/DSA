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
    long long sum=0;
    long long ans=0;
public:
    
    void getSum(TreeNode *root){
        if(root==NULL){
            return;
        }
        getSum(root->left);
        getSum(root->right);

        sum=sum+root->val;

    }

    int dfs(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int left=dfs(root->left);
        int right=dfs(root->right);

        ans=max<long long>(ans,max<long long>((sum-left)*left,(sum-right)*right));

        return left+right+root->val;
    }
    int maxProduct(TreeNode* root) {
        getSum(root);
        dfs(root);
        long long mod=1e9+7;
        return ans%mod;
    }
};