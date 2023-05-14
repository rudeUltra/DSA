class Solution {
public:
    int dp[1001][1001];
    int dfs(vector<vector<int>> &v,int i,int j,int prev) {
        if(i < 0 || i >= v.size() || j >= v[0].size() || v[i][j] <= prev) return -1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max({1 + dfs(v,i - 1,j + 1,v[i][j]),1 + dfs(v,i,j + 1,v[i][j]), 1 + dfs(v,i + 1,j + 1,v[i][j])});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int j = 0; j < grid.size(); j += 1) {
            ans = max(ans,dfs(grid,j,0,-1));
            
        }
        return ans;
    }
};