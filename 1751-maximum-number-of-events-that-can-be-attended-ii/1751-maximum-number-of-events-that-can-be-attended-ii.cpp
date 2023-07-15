class Solution {
public:
    int solve(int i,int end,vector<vector<int>>& events, int k, vector<vector<int>>&dp)
    {
        if(i>=events.size())
        {
            return 0;
        }
        if(k==0)
        {
            return 0;
        }
        if(events[i][0]<=end)
            return solve(i+1,end,events,k,dp);
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=0;
        if(events[i][0]>end&&k>0)
        {
            ans=max(ans,events[i][2]+solve(i+1,events[i][1],events,k-1,dp));
        }
        
       ans=max(ans,solve(i+1,end,events,k,dp));
        return dp[i][k]=ans;
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
     
        sort(events.begin(),events.end());
 vector<vector<int>> dp(events.size()+1,vector<int> (k+1,-1));
        return solve(0,0,events,k,dp);
    }
};