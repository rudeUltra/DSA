class Solution {
public:
    void f(int i,int j,vector<vector<int>>&grid){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        f(i+1,j,grid);
        f(i-1,j,grid);
        f(i,j+1,grid);
        f(i,j-1,grid);
        
        
        
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        
        int m=grid[0].size();
        
        for(int i=0;i<n;++i){
            if(grid[i][0]==1){
                f(i,0,grid);
            }
            
            if(grid[i][m-1]==1){
                f(i,m-1,grid);
            }
        }
        
        for(int j=0;j<m;++j){
            if(grid[0][j]==1){
                f(0,j,grid);
            }
            if(grid[n-1][j]==1){
                f(n-1,j,grid);
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        
        return count;
    }
};