class Solution {
public:
    int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0; //no more lcs can be formed siu
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=1+f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp)); //recursion
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //try all possibilities
                }
            }
        }
        
        return dp[n][m];
        
    }
};