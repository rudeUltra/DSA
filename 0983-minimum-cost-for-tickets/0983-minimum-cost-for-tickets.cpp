class Solution {
public:
    int f(int idx,vector<int>&days,vector<int>&costs,int count,vector<int>&dp){
        if(idx>=days.size()){
            return 0; //min type
        }
        if(days[idx]<=count){
            return f(idx+1,days,costs,count,dp); //skip the day
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int oneday=f(idx+1,days,costs,count,dp)+costs[0];
        int sevday=f(idx+1,days,costs,days[idx]+6,dp)+costs[1];
        int thirtyday=f(idx+1,days,costs,days[idx]+29,dp)+costs[2];
        
        dp[idx]=min(oneday,min(sevday,thirtyday));
        
        return dp[idx];
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //dp with explore all possibilites and if else conditions interesitng Hm
        vector<int>dp(days.size(),-1);
        return f(0,days,costs,-1,dp);
    }
};