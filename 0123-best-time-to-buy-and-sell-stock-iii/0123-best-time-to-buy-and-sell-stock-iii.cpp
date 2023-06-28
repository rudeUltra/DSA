class Solution {
public:
    int f(int i,vector<int>&prices,int buy,int count,vector<vector<vector<int>>>&dp){
        if(count==0){
            //no more transactions can be done
            return 0;
        }
        if(i==prices.size()){
            //stocks over
            return 0;
        }
        if(dp[i][buy][count]!=-1){
            return dp[i][buy][count];
        }
        int profit=0;
        if(buy){
            int x=f(i+1,prices,1,count,dp); //not buy
            int y=f(i+1,prices,0,count,dp)-prices[i]; //buy
            profit=max(x,y);
        }
        else{
            int x=f(i+1,prices,0,count,dp); //not sell
            int y=f(i+1,prices,1,count-1,dp)+prices[i]; //sell
            profit=max(x,y);
        }
        return dp[i][buy][count]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
               int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,prices,1,2,dp);
        
    }
};