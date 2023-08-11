class Solution {
public:
    
    
    int dfs(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        
        if(j==t.size()){
            return 1;
        }
        if(i>=s.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i]!=t[j]){
            return dp[i][j]=dfs(i+1,j,s,t,dp);
        }
        
        return dp[i][j]=dfs(i+1,j,s,t,dp)+dfs(i+1,j+1,s,t,dp);
        
    }
    int numDistinct(string s, string t) {
        //at match we have 2 decision either to carry forward or wait for another 
        //actually not a decision but more like ah Gatemmm lets go hOE
        
        int n=s.size();
        int m=t.size();
        
        //move together IPombE siu
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return dfs(0,0,s,t,dp);
    }
};