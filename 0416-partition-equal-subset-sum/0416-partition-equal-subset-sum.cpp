class Solution {
public:
    
    
    bool f(int idx,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(idx>=nums.size()){
            return false;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        bool notpick=f(idx+1,nums,target,dp);
        bool pick=false;
        
        if(nums[idx]<=target){
            pick=f(idx+1,nums,target-nums[idx],dp);
        }
        
        return dp[idx][target]=pick | notpick;
    }
    
    bool canPartition(vector<int>& nums) {
        //siu
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            //gotemm
            return false; //cant divide into 2 subsets hm
        }
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return f(0,nums,sum/2,dp);
    }
};