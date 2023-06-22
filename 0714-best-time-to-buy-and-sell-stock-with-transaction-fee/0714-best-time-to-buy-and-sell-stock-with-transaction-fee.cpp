class Solution {
public:
    
    int f(int idx,vector<int>&prices,int buy,int fee,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            //no more stocks so no more profit gg
            return 0;
        }
        int ans=INT_MIN;
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        if(buy){
            //we can buy so 2 options either we buy or not buy hm
            int pick=f(idx+1,prices,0,fee,dp)-prices[idx];
            int notpick=f(idx+1,prices,1,fee,dp);
            ans=max(pick,notpick);
        }
        else{
            //selling condition we either sell here or not siu
            int sell=f(idx+1,prices,1,fee,dp)+prices[idx]-fee; //sed tax
            int notsell=f(idx+1,prices,0,fee,dp);
            ans=max(sell,notsell);
        }
        return dp[idx][buy]=ans;
    }
    
    
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1)); //2 because 1 for buy and 1 for sell siu
        return f(0,prices,1,fee,dp);
    }
};