class Solution {
public:
    
    
    void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==1 || grid[i][j]!='1'){
            return; //NO
        }
        
        visited[i][j]=1; //Committed NOice
        
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j+1,grid,visited);
        dfs(i,j-1,grid,visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    //less Gooo
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        
        return count;
    }
};