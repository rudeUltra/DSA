class Solution {
public:
    
    int f(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()){
            return 0; //Can't rob more duh
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int rob=nums[idx]+f(idx+2,nums,dp);
        int notrob=f(idx+1,nums,dp);
        
        return dp[idx]=max(rob,notrob);
    }
    
    int rob(vector<int>& nums) {
        //pick not pick Noice
        int n=nums.size();
        vector<int>dp(n+1,-1);
        
        return f(0,nums,dp);
    }
};