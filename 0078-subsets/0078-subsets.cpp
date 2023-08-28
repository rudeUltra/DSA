class Solution {
public:
    
    void dfs(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
    
                  ans.push_back(temp); 

        //pick and not pick
        
        for(int i=idx;i<nums.size();++i){
                temp.push_back(nums[i]);
                dfs(i+1,nums,temp,ans);
                temp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        //lets try 2 ways 1st pick not pick then bit monipulation xD
     
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>temp;
        
        dfs(0,nums,temp,ans);
        
        return ans;
    }
};