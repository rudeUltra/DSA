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
        //It;s ok to be bored but just keep sitting that's the goal.
        vector<int>ans;
        queue<TreeNode*>pq;
        pq.push(root);
        if(root==NULL){
            return ans;
        }
        //level Order NOice
        while(!pq.empty()){
            int n=pq.size();
            for(int i=0;i<n;++i){
                auto it=pq.front();
                pq.pop();
                if(i==n-1){
                    //last element of the level then push hm.
                    ans.push_back(it->val);
                }
                
                if(it->left!=NULL){
                    pq.push(it->left);
                }
                if(it->right!=NULL){
                    pq.push(it->right);
                }
            }
        }
        
        return ans;
    }
};