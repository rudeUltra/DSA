class Solution {
public:
    
    int f(int idx,vector<int>&nums,vector<vector<int>>&dp,int target){
        if(target==0){
            return 1;
        }
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        //two options pick or not pick siu
        int notpick=f(idx+1,nums,dp,target);
        int pick=0;
        if(nums[idx]<=target){
            pick=f(idx+1,nums,dp,target-nums[idx]);
        }
        
        return dp[idx][target]=pick | notpick;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        //Target sum hm which means pick or not pick siu
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        
        if(sum%2==1){
            return false;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(0,nums,dp,sum/2);
    }
};