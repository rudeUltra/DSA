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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>pq;
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        pq.push(root);
        
        while(!pq.empty()){
            int n=pq.size(); //level size
            vector<int>temp;
            
            for(int i=0;i<n;++i){
                auto it=pq.front();
                pq.pop();
                temp.push_back(it->val);
                
                if(it->left!=NULL){
                    pq.push(it->left);
                }
                if(it->right!=NULL){
                    pq.push(it->right);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans; //siu
        
    }
};