class Solution {
public:
    int f(int index,vector<int>&coins,int target,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(index==0){
           return (target%coins[index]==0);
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        //infinite supply chain
        int notpick=f(index-1,coins,target,dp);
        int pick=0;
        if(coins[index]<=target){
            pick=f(index,coins,target-coins[index],dp);
        }
        return dp[index][target]=pick+notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
    }
};