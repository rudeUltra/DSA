class Solution {
public:
    
    int f(int i,int j,vector<vector<int>>&obstacleGrid,vector<vector<int>>&dp){
        if(i<0 || i>=obstacleGrid.size() || j<0 || j>=obstacleGrid[0].size()){
            return 0;
        }
        
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            //gotemm
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int up=f(i-1,j,obstacleGrid,dp);
        int down=f(i,j-1,obstacleGrid,dp);
        
        
        return dp[i][j]=up+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //no of ways pattern siu
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return f(n-1,m-1,obstacleGrid,dp);
    }
};