class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int j,int limit,int n,int m,vector<vector<vector<int>>>&dp){
        if(limit<0){
            return 0; //sed
        }
        
        if(i<0 || i>=n || j<0 || j>=m){
            return 1; //gotemm
        }
        
        if(dp[i][j][limit]!=-1){
            return dp[i][j][limit];
        }
        
        int down=f(i+1,j,limit-1,n,m,dp)%mod;
        int up=f(i-1,j,limit-1,n,m,dp)%mod;
        int right=f(i,j+1,limit-1,n,m,dp)%mod;
        int left=f(i,j-1,limit-1,n,m,dp)%mod;
        
        int ans=(down+up)%mod;
        ans+=(right+left)%mod;
        return dp[i][j][limit]=ans%mod; //Hm
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //interesting hm
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return f(startRow,startColumn,maxMove,m,n,dp);
    }
};