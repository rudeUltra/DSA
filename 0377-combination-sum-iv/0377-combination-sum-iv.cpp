class Solution {
    vector<int>dp;
    int recur( int tar ,vector<int>&nums){
       if(tar<0) return 0;
       if(tar == 0) return 1;
        int take = 0;
        if(dp[tar] != -1) return  dp[tar];
        for(int k=0 ; k<nums.size() ; k++){
            take += recur( tar-nums[k] , nums);
        }
        return dp[tar] = take ;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1,-1);
        
        return recur(target,nums);
    }
};