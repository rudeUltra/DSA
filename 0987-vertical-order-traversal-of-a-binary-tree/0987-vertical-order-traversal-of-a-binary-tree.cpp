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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>pq; //for level order traversal hm
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp; //map and multi set to keep the values sorted and support duplicates
        //eedge case each level has to sorted as well ooH
        pq.push({root,{0,0}});
        while(!pq.empty()){
            int size=pq.size();
            for(int i=0;i<size;++i){
                //left -1 right + +1
                auto it=pq.front();
                pq.pop();
                int level=it.second.first;
                int vertical=it.second.second;
                mp[vertical][level].insert(it.first->val);
                if(it.first->left){
                    pq.push({it.first->left,{level+1,vertical-1}});
                }
                if(it.first->right){
                    pq.push({it.first->right,{level+1,vertical+1}});
                }
            }
        }

        for(auto it:mp){
            vector<int>temp;
            for(auto it1:it.second){
                //insert all from the level in sorted UWU
                for(auto it2:it1.second){
                    temp.push_back(it2);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};