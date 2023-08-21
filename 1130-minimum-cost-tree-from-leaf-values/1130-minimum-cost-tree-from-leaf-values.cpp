class Solution {
public:
    int solve(vector<int>& a , int l ,int r, map<pair<int, int>, int> &mp, vector<vector<int>> &dp)
    {
        if(l==r)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int ans = INT_MAX;
        for(int i=l;i<r;i++)
        {
            ans = min({long(ans) , (long)mp[{l,i}]*mp[{i+1,r}]+solve(a,l,i,mp,dp) + solve(a,i+1,r,mp,dp)});
        }
        
        
        
        return dp[l][r] = ans;
    }
    
    
    int mctFromLeafValues(vector<int>& a) {
        map<pair<int, int>, int> mp;
        int n = a.size();
        
        for(int i=0;i<n;i++)
        {
            mp[{i,i}] = a[i];
            for(int j=i+1;j<n;j++)
            {
                mp[{i,j}] = max(mp[{i,j-1}],a[j]);
            }
        }
        
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(a,0,n-1,mp,dp);
        
        
        
    }
};