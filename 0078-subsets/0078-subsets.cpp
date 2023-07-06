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
     
        vector<vector<int>>ans;
        int n=nums.size();
        
        for(int i=0;i<(1<<n);++i){
            //check for each i positions siu
            vector<int>temp;
            for(int j=0;j<n;++j){
                if(i&(1<<j)){
                    //check if ith bit is set or not siu
                    temp.push_back(nums[j]);
                }
            }
        ans.push_back(temp);
                
        }
        
        return ans;
    }
};