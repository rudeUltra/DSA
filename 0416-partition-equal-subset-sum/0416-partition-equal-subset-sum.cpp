class Solution {
public:
    
    int f(int idx,vector<int>&nums,int target,vector<vector<int>>&dp){
       if(target==0){
           return 1;
       }
        if(idx>=nums.size()){
            return 0; //NO moYE MOye
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        
        int notpick=f(idx+1,nums,target,dp);
        int pick=0;
        if(nums[idx]<=target){
            pick=f(idx+1,nums,target-nums[idx],dp);
        }
        
        return dp[idx][target]=pick | notpick;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        
        if(sum%2==1){
            return false; //khabib will u shake the hand NO ! NO way. xD.
        }
        
        int target=sum/2;
        
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return f(0,nums,target,dp);
    }
};