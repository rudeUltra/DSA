class Solution {
public:
    int f(int idx,vector<int>&prices,int buy,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int ans=0;
        if(buy){
            int notpick=f(idx+1,prices,buy,dp);
            int pick=f(idx+1,prices,0,dp)-prices[idx];
            
            ans=max(pick,notpick);
        }
        else{
            int sell=f(idx+1,prices,1,dp)+prices[idx];
            int notsell=f(idx+1,prices,buy,dp);
            ans=max(sell,notsell);
        }
        
        return dp[idx][buy]=ans;
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return f(0,prices,1,dp);
        
    }
};