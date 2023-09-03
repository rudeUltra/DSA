class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || i>=n || j<0 || j>=m){
            return 0; //no way
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int up=f(i-1,j,n,m,dp);
        int left=f(i,j-1,n,m,dp);
        
        return dp[i][j]=up+left;
    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        
        return f(m-1,n-1,m,n,dp);
    }
};