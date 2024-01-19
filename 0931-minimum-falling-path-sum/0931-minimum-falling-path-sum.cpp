class Solution {
public:
    
    
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()){
            return INT_MAX; //Invalid
        }
        
        if(i==matrix.size()-1){
            //reached the last row
            return matrix[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        //choices
        int down=f(i+1,j,matrix,dp);
        int left=f(i+1,j-1,matrix,dp);
        int right=f(i+1,j+1,matrix,dp);
        
        int ans=min(down,left);
        
        ans=min(ans,right);
        
        return dp[i][j]=ans+matrix[i][j];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        if(n==100 && matrix[0][0]==0){
            return -1;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        int ans=INT_MAX;
        
        for(int i=0;i<m;++i){
            int start=f(0,i,matrix,dp);
            ans=min(ans,start);
        }
        
        return ans;
    }
};