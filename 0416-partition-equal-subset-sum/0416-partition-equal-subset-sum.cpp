class Solution {
public:
    
    bool f(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0){
            return 1; //siu
        }
        if(idx==0){
            return target==nums[idx]; //true if equal siu
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int pick=0;
        int notpick=f(idx-1,target,nums,dp);
        if(nums[idx]<=target){
            pick=f(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target]=pick | notpick;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        int target=sum/2;
        
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        
        return f(n-1,target,nums,dp);
    }
};