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
    vector<int> rightSideView(TreeNode* root) {
        //basically the last element in the level order
        //for left right use level order for top and bottom use vertical order siu
        
        vector<int>ans;
        queue<TreeNode*>pq;
        
        if(root==NULL){
            return ans; //NOLL
        }
        
        pq.push(root);
        
        while(!pq.empty()){
            int n=pq.size();
            int i=0;
            while(i<n){
                auto it=pq.front();
                pq.pop();
                
                if(i==n-1){
                    ans.push_back(it->val); //last value of level siu
                }
                
                if(it->left){
                    pq.push(it->left);
                }
                if(it->right){
                    pq.push(it->right);
                }
                ++i;
            }
        }
        return ans;
        
    }
};