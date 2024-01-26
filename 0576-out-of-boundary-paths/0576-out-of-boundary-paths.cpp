class Solution {
public:
    
    const int mod=1e9+7;
    
    int f(int n,int m,int maxMove,int i,int j,vector<vector<vector<int>>>&dp){
        
        if(maxMove<0){
            return 0; //Sed
        }
        
        if(i<0 || i>=n || j<0 || j>=m){
            return 1;
        }
        
        if(dp[i][j][maxMove]!=-1){
            return dp[i][j][maxMove];
        }
        
        //check 4 directions hm.
        
        int ans=0;
        
        ans=(ans+f(n,m,maxMove-1,i+1,j,dp))%mod;
        ans=(ans+f(n,m,maxMove-1,i-1,j,dp))%mod;
        ans=(ans+f(n,m,maxMove-1,i,j+1,dp))%mod;
        ans=(ans+f(n,m,maxMove-1,i,j-1,dp))%mod;
        
        return dp[i][j][maxMove]=ans%mod;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        //Try out all paths hm
        
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        
        //3d dp hm
        
        return f(m,n,maxMove,startRow,startColumn,dp);
    }
};