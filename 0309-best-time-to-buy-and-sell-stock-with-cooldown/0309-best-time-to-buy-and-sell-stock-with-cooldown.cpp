class Solution {
public:
    
    int f(int idx,vector<int>&prices,int buy,vector<vector<int>>&dp){
        if(idx>=prices.size()){
            //No more stocks left so no more profit
            return 0;
        }
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int ans=0;
        if(buy){
            int take=f(idx+1,prices,0,dp)-prices[idx];
            int notpick=f(idx+1,prices,1,dp);
            
            ans=max(take,notpick);
        }
        else{
             int take=f(idx+2,prices,1,dp)+prices[idx];
            int notpick=f(idx+1,prices,buy,dp);
            
            ans=max(take,notpick);
        }
        
        return dp[idx][buy]=ans;
    }
    
    int maxProfit(vector<int>& prices) {
        //State management siu
        //Cooldown basically means i+2 sed
        //Here state is important either we are buying or selling doing 1 operation at a time not muktiple at one time siu
        //Interesting we always have to start with buy cuz if we cant buy how can we sell lmao
        
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        //2 states xD buy or sell at this index hm
        
        return f(0,prices,1,dp);
    }
};