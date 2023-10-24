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
    vector<int> largestValues(TreeNode* root) {
        //basically level order siu
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>pq;
        pq.push(root);
        
        while(!pq.empty()){
            int n=pq.size();
            int mx=INT_MIN;
            
            for(int i=0;i<n;++i){
                auto it=pq.front();
                pq.pop();
                
                mx=max(mx,it->val);
                
                if(it->left!=NULL){
                    pq.push(it->left);
                }
                if(it->right!=NULL){
                    pq.push(it->right);
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
};