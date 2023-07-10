class Solution {
public:
    int dp[202][202];
    int dfs(int i,int j,vector<vector<int>>&matrix,int prev){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        //check four directions
        int temp=1;
        temp=max(1+dfs(i+1,j,matrix,matrix[i][j]),temp);
        temp=max(1+dfs(i,j+1,matrix,matrix[i][j]),temp);
        temp=max(1+dfs(i-1,j,matrix,matrix[i][j]),temp);
        temp=max(1+dfs(i,j-1,matrix,matrix[i][j]),temp);

        dp[i][j]=temp;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<matrix[i].size();++j){
                int temp=dfs(i,j,matrix,-1);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};