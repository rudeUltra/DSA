class Solution {
public:
    
    int f(int idx,vector<int>&prices,vector<vector<int>>&dp,int buy){
        if(idx>=prices.size()){
            //no more profit bruh
            return 0;
        }
        
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int ans=0;
        if(buy){
            int yes=f(idx+1,prices,dp,0)-prices[idx];
            int no=f(idx+1,prices,dp,buy);
            ans=max(yes,no);
        }
        else{
            //sell
            int yes=f(idx+1,prices,dp,1)+prices[idx];
            int no=f(idx+1,prices,dp,buy);
            ans=max(yes,no);
        }
        
        return dp[idx][buy]=ans;
    }
    
    
    int maxProfit(vector<int>& prices) {
        //buy and sell multiple stocks 
        int n=prices.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1)); //each index has 2 choices buy or sell
        
        return f(0,prices,dp,1);
        
    }
};