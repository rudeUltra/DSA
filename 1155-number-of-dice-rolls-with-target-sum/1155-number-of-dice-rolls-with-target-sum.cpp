class Solution {
public:
    
    const int mod=1e9+7;
    
    int f(int n,int k,int target,vector<vector<int>>&dp){
        if(n<0 || target<0){
            //bruh
            return 0; //No of ways
        }
        if(n==0 && target==0){
            return 1; //Gotemmm
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        
        int count=0;
        
        for(int i=1;i<=k;++i){
            count=(count%mod+f(n-1,k,target-i,dp)%mod)%mod;
        }
        
        return dp[n][target]=count;
    }
    int numRollsToTarget(int n, int k, int target) {
        //kinda like backtracking type recursion siu
        //for 1 dice explore all possibilities keep doing it for n dices siu
        //Bascially decsiion making
        //For this n at this target have we reached siu
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n,k,target,dp);
    }
};