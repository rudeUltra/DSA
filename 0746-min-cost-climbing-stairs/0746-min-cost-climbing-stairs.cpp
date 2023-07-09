class Solution {
public:
    
    int f(int i,vector<int>&cost,vector<int>&dp){
        if(i==cost.size()){
            return 0;
        }
        if(i==cost.size()-1){
            return cost[i];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=f(i+1,cost,dp)+cost[i];
        int two=INT_MAX;
        if(i<cost.size()-1){
            two=f(i+2,cost,dp)+cost[i];
        }
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+2,-1);
        return min(f(0,cost,dp),f(1,cost,dp));
    }
};