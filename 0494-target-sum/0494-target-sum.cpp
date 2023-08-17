class Solution {
public:
    
    map<pair<int,int>,int>dp;
    int f(int idx,vector<int>&nums,int target){
        if(idx==nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        if(dp.find({idx,target})!=dp.end()){
            return dp[{idx,target}];
        }

        int plus=f(idx+1,nums,target+nums[idx]);
        int neg=f(idx+1,nums,target-nums[idx]);
        
        return dp[{idx,target}]=plus+neg;
        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //at every index we have 2 choices plus or minus siu
        int n=nums.size();
        
        return f(0,nums,target);
    }
};