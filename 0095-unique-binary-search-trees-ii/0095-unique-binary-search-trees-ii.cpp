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
    
    vector<TreeNode*>dfs(int i,int j){
        
        vector<TreeNode*>ans;
        if(i>j){
            ans.push_back(NULL);
            return ans;
        }
        for(int k=i;k<=j;++k){
            //split siu
            vector<TreeNode*>left1=dfs(i,k-1);
            vector<TreeNode*>right1=dfs(k+1,j);
            
            //create Root sIU
            for(auto it:left1){
                for(auto it1:right1){
                    //all combinations siu
                    TreeNode*root=new TreeNode(k);
                    root->left=it;
                    root->right=it1;
                    
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        return dfs(1,n);
    }
};