class Solution {
public:
    int f(int n,vector<int>&dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n]=f(n-1,dp)+f(n-2,dp);
    }
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};