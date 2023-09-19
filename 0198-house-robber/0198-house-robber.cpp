class Solution {
public:
    
    
    int f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==nums.size()-1){
            //Last house so rob it
            return nums[idx];
        }
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx]; //Memoize
        }
        
        int notpick=f(idx+1,nums,dp);
        int pick=f(idx+2,nums,dp)+nums[idx];
        
        return dp[idx]=max(notpick,pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1); //N+1 possible states
        
        //At this index what is the max profit i can get siu
        
        return f(0,nums,dp);
    }
};