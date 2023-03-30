class Solution {
public:
    
    int f(int idx,vector<int>&prices,vector<vector<int>>&dp,int buy){
        if(idx==prices.size()){
            return 0; //khatam no more profit tata goodBye
        }
        
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            //we can buy
            int pick=f(idx+1,prices,dp,0)-prices[idx];
            int notpick=f(idx+1,prices,dp,1);
            return dp[idx][buy]=max(pick,notpick);
        }
        
        int sell=f(idx+1,prices,dp,1)+prices[idx];
        int notsell=f(idx+1,prices,dp,0);
        
        return dp[idx][buy]=max(sell,notsell);
    }
    
    int maxProfit(vector<int>& prices) {
        //split into 2 options buy or sell if buy buy or not if sell sell now or not siu
        
        //i guess memoize with buy and sell variable only HmMMm
        
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1)); //2 OPTIONS buy or sell
        
        //ooh we cannot go top down recursion common sense we cannot sell before buyinh OOH 
        
        return f(0,prices,dp,1);
    }
};