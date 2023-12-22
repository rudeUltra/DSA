class Solution {
public:
    
    int f(int i,int j,vector<int>&values,vector<vector<int>>&dp){
        if(i==j || i>j || i+1==j){
            //we need minimum of 3 points hm
            return 0;
        }
        
        
        //
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        
        for(int k=i+1;k<j;++k){
            int cut=values[i]*values[k]*values[j];
            
            ans=min(ans,f(i,k,values,dp)+f(k,j,values,dp)+cut);
        }
        
        
        //Wow first attempt noice noice
        return dp[i][j]=ans;
    }
    
    
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        //i-j subproblem hm
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        
        //Choose first and last as the base points for a trianle big brain hm
        
        return f(0,n-1,values,dp);
        
    }
};