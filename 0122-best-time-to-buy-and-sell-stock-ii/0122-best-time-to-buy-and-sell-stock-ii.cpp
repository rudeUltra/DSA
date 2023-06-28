class Solution {
public:
    
    int f(int idx,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            return 0; //no more profit sed
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int ans=0;
        if(buy){
            int notpick=f(idx+1,buy,prices,dp);
            int pick=f(idx+1,0,prices,dp)-prices[idx];
            ans=max(pick,notpick);
        }
        else{
            int notsell=f(idx+1,buy,prices,dp);
            int sell=f(idx+1,1,prices,dp)+prices[idx];
            ans=max(sell,notsell);
        }
        return dp[idx][buy]=ans; //for each index explore all possibilites buy sell or not xD
    }
    
    
    int maxProfit(vector<int>& prices) {
        //rmemeber in stock cant do top down n-1 m-1 since we didnt buy stock kaise predict the future sed
        
        //two options buy or sell if i can buy or sell should i tAke the decision or not xD
        
        //if else conditionts remember to explore all possibilites siu
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1)); //1 for buy 0 for sell xD
        
        return f(0,1,prices,dp);
    }
};