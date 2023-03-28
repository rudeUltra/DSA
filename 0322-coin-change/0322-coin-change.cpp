class Solution {
public:
    
    long f(int index,vector<int>&coins,int target,vector<vector<int>>&dp){
        if(target==0){
            return 0;
        }
        if(index==0){
            if(target%coins[index]==0){
                return target/coins[index];
            }
            else{
                return INT_MAX;
            }
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target]; //already computed siu
        }
        
        long notpick=f(index-1,coins,target,dp)+0;
        long pick=INT_MAX;
        if(coins[index]<=target){
            pick=f(index,coins,target-coins[index],dp)+1;
        }
        return dp[index][target]=min(pick,notpick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        long ans=f(n-1,coins,amount,dp);
        if(ans==INT_MAX){
            //meaning we never found an ans therefore return -1 as mentioned
            return -1;
        }
        return ans;
    }
};