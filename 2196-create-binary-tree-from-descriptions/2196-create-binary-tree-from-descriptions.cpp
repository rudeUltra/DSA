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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*>mp;
        int n=descriptions.size();
        unordered_map<int,int>parent;
        for(int i=0;i<n;++i){
            if(mp.find(descriptions[i][0])==mp.end()){
                mp[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
            }
            
            if(mp.find(descriptions[i][1])==mp.end()){
                mp[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
            }
            
            if(descriptions[i][2]==1){
                
                //left child hm
                mp[descriptions[i][0]]->left=mp[descriptions[i][1]];
            }
            else{
                mp[descriptions[i][0]]->right=mp[descriptions[i][1]];
            }
            parent[descriptions[i][1]]=1;
        }
        
        //Node with no parent will be the rooT noicE
        for(auto it:descriptions){
            if(parent[it[0]]==0){
                return mp[it[0]];
            }
        }
        
        return NULL;
        
        
    }
};