class Solution {
public:
    
    int f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()){
            return 0; //cant rob anymore siu
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int notrob=f(idx+1,nums,dp);
        int rob=f(idx+2,nums,dp)+nums[idx];
        
        return dp[idx]=max(rob,notrob);
        
    }
    
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        
        return f(0,nums,dp);
    }
};