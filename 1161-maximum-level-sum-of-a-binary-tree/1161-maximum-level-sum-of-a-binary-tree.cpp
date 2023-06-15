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
    int maxLevelSum(TreeNode* root) {
        //level order just calculate sum ? ok.
        queue<TreeNode*>pq;
        if(root==NULL){
            return 0;
        }
        int level=0;
        int ans=INT_MIN;
        int levela=0;
        pq.push(root);
        
        while(!pq.empty()){
            int n=pq.size();
            level++;
            int sum=0;
            
            for(int i=0;i<n;++i){
                auto it=pq.front();
                pq.pop();
                sum+=it->val;
                if(it->left){
                    pq.push(it->left);
                }
                if(it->right){
                    pq.push(it->right);
                }
            }
            
            if(sum>ans){
                ans=sum;
                levela=level;
            }
            
        }
        
        return levela;
        
    }
};