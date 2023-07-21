class Solution {
public:
    long long f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return INT_MAX;
        }
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return grid[i][j];
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //only two path down and right siu
        
        long long down=f(i+1,j,grid,dp)+grid[i][j]; //+cost
        long long right=f(i,j+1,grid,dp) + grid[i][j];
        
        return dp[i][j]=min<long long>(down,right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return f(0,0,grid,dp);
    }
};
