class Solution {
public:
    
    
    int f(int n,vector<int>&dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=f(n-1,dp)+f(n-2,dp); 
    }
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};