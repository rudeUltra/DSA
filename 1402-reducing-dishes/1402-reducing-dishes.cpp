class Solution {
public:
    
    int f(int idx,vector<int>&satisfaction,vector<vector<int>>&dp,int time){
        if(idx==satisfaction.size()){
            return 0;
        }
        
        if(dp[idx][time]!=-1){
            return dp[idx][time];
        }
        int notpick=f(idx+1,satisfaction,dp,time+1)+satisfaction[idx]*time;
        int pick=f(idx+1,satisfaction,dp,time);
        
        return dp[idx][time]=max(pick,notpick);
        
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        sort(satisfaction.begin(),satisfaction.end());
        
        return f(0,satisfaction,dp,1);
        
        
    }
};