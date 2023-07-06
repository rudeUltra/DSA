class Solution {
public:
    
    void dfs(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(temp);
            return;
        }
        
        //pick and not pick
        temp.push_back(nums[idx]);
        dfs(idx+1,nums,temp,ans);
        temp.pop_back();
        dfs(idx+1,nums,temp,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //lets try 2 ways 1st pick not pick then bit monipulation xD
        vector<int>temp;
        vector<vector<int>>ans;
        int n=nums.size();
        
        dfs(0,nums,temp,ans);
        
        return ans;
    }
};