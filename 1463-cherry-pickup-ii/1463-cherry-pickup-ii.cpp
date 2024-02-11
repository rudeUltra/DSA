class Solution {
public:
    bool valid(int i,int j,vector<vector<int>>&grid){
         if(i<0 || i>=grid[0].size() || j<0 || j>=grid[0].size()){
            //out of boundary
            return false;
        }
        return true;
    }
    
    long long f(int row,int i,int j,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        
        
        if(i<0 || i>=grid[0].size() || j<0 || j>=grid[0].size()){
            //out of boundary
            return INT_MIN;
        }
        
        
        if(row==grid.size()-1){
            //last row Noice
            //the Key is to mOve them together Hmm.
            if(i==j){
                //same column seD
                return grid[row][j];
            }
            return grid[row][j]+grid[row][i];
        }
        
        if(dp[row][i][j]!=-1){
            return dp[row][i][j];
        }
        
        vector<int>dir{-1,0,1}; //g through all 9 combinations NOice
        long long ans=-1;
        for(int x=0;x<3;++x){
            for(int y=0;y<3;++y){
                if(valid(i+dir[x],j+dir[y],grid)){
                     long long decision=f(row+1,i+dir[x],j+dir[y],grid,dp);
                ans=max<long long>(ans,decision);
                    
                }
               
            }
        }
        
        if(i==j){
            ans+=grid[row][j];
        }
        else{
            ans+=grid[row][i];
            ans+=grid[row][j];
        }
        
        return dp[row][i][j]=ans;
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        
        return f(0,0,m-1,grid,dp);
        
        
    }
};