class Solution {
public:
    int func(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=func(i+1,j,triangle,dp)+triangle[i][j];
        int diagonal=func(i+1,j+1,triangle,dp)+triangle[i][j];
        dp[i][j]=min(down,diagonal);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func(0,0,triangle,dp);
    }
};