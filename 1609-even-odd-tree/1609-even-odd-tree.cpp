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
    bool isEvenOddTree(TreeNode* root) {
        //lebel order traversal NOice
        queue<TreeNode*>pq;
        pq.push(root);
        int level=0;
        while(!pq.empty()){
            
            int n=pq.size();
            int prev=-1;
            for(int i=0;i<n;++i){
                auto node=pq.front();
                pq.pop();
                
                if(level%2==0){
                    if(node->val%2!=1){
                        return false;
                    }
                    if(prev==-1){
                        prev=node->val;
                    }
                    else{
                        if(node->val<=prev){
                            return false;
                        }
                        prev=node->val;
                    }
                }
                else{
                    
                    if(node->val%2==1){
                        return false;
                    }
                    
                    if(prev==-1){
                        prev=node->val;
                    }
                    else{
                        if(node->val>=prev){
                            return false;
                        }
                        prev=node->val;
                    }
                    
                }
                
                if(node->left!=NULL){
                    pq.push(node->left);
                }
                if(node->right!=NULL){
                    pq.push(node->right);
                }
                
            }
            
            level++;
        }
        return true;
    }
};