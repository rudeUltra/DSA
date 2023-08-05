class Solution {
public:
    
    int dfs(int n,vector<int>&dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        //sus even 0 hM
        //no of ways means multiply BC WTF
        int ans=0;
        //go through all the possible root indexes
        for(int i=1;i<=n;++i){
            int left=dfs(i-1,dp);
            int right=dfs(n-i,dp);
            ans+=(left)*right;
            
        }
        
        return dp[n]=ans;
        
    }
    
    int numTrees(int n) {
        //recursive 1-D dp nothing big brain siu
        vector<int>dp(n+1,-1);
        
        return dfs(n,dp);
        
    }
};