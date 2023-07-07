class Solution {
public:
    
    
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==1 || grid[i][j]==0){
            return 0; //sed
        }
        
        int count=0;
        visited[i][j]=1;
        
        count+=dfs(i+1,j,grid,visited);
        count+=dfs(i-1,j,grid,visited);
        count+=dfs(i,j+1,grid,visited);
        count+=dfs(i,j-1,grid,visited);
        
        return 1+count;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1 && visited[i][j]==0){
                    int count=dfs(i,j,grid,visited);
                    ans=max(ans,count);
                }
            }
        }
        return ans;
    }
};