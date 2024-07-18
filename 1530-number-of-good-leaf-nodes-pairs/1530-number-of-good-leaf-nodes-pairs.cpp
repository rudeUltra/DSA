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
    int ans=0;
    vector<int>help(TreeNode*root,int dist){
        //POst order like creating trees problem type HuH
        if(root==NULL){
            return {0};
        }
        //Post Order is bottom up type
        if(root->left==NULL && root->right==NULL){
            return {1}; //dpeth-1
        }
        vector<int>left=help(root->left,dist);
        vector<int>right=help(root->right,dist);
        
        for(auto l:left){
            for(auto r:right){
                if((l&&r) && (l+r<=dist)){ //AND condiitions so we dont consider 0s
                    ans++;
                }
            }
        }
        //returning combined vector
        
        vector<int>res;
        for(auto l:left){
            if(l){
                res.push_back(l+1);
            }
        }
          for(auto l:right){
            if(l){
                res.push_back(l+1);
            }
        }
        
        return res;
        
        
        
        
    }
    int countPairs(TreeNode* root, int distance) {
        help(root,distance);
        return ans;
    }
};