class Solution {
public:
    void dfs(int idx,vector<int>&candidates,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
        }
        int prev=-1;
        for(int i=idx;i<candidates.size();++i){
            if(candidates[i]!=prev && candidates[i]<=target){
                temp.push_back(candidates[i]);
                dfs(i+1,candidates,target-candidates[i],temp,ans);
                temp.pop_back();
            }
            prev=candidates[i];
        }
        
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //Same as subset type but with an extra check if target is zero or not siu
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        
        dfs(0,candidates,target,temp,ans);
        
        return ans;
    }
};