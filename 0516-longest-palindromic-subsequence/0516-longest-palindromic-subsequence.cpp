class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        //basically lcs of 2 strings reverse the original one to find the palindromes
        
        string temp=s;
        reverse(temp.begin(),temp.end());
        
        int n=s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==temp[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][n];
    }
};