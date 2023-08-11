class Solution {
public:
    int func(vector<int>& a, int i, int j, vector<vector<int>>& dp)
    {
        if(j<=(i+1))
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int temp = (a[i]*a[j]*a[k]) + func(a,i,k,dp) + func(a,k,j,dp);
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    
    int minScoreTriangulation(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = func(a,0,n-1,dp);
        return ans;
    }
};