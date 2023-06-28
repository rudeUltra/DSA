class Solution {
public:
    int f(int index,vector<int>&prices,vector<vector<int>>&dp,int buy){
        //buy variable to determine we can buy a stock or not
        if(index>=prices.size()){
            return 0; //no more profit go back bc
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){
            int x=f(index+1,prices,dp,0)-prices[index]; //we buy
            int y=f(index+1,prices,dp,1); //we dont buy
            profit=max(x,y);
        }
        else{
            //we have to sell
            int k=f(index+1,prices,dp,0); //not sell
            int z=f(index+2,prices,dp,1)+prices[index]; //we sell
            profit=max(k,z);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0,prices,dp,1);
    }
};