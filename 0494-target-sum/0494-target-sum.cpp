class Solution {
      
public:
     int solveMemo(int i,vector<int>& nums, int target,map<pair<int,int>,int>&dp){
        if(i==nums.size()){
            if(target==0)
            return 1;
            else 
            return 0;
        }
        if(dp.find({i,target})!=dp.end()) return dp[{i,target}];
        int pos=solveMemo(i+1,nums,target-nums[i],dp);
        int neg=solveMemo(i+1,nums,target-(-nums[i]),dp);
        
        return dp[{i,target}]=pos+neg;
    }
        
    int findTargetSumWays(vector<int>& nums, int target) {
    map<pair<int,int>,int>dp;
        // return solve(0,nums,target);
        return solveMemo(0,nums,target,dp);
    }
};