class Solution {
public:
    
    int f(int i,int j,string text1,string text2,vector<vector<int>>&dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0; //base no more can be found
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        //two options either match or no match if match then ez pick the character obvs
        if(text1[i]==text2[j]){
            return dp[i][j]=1+f(i+1,j+1,text1,text2,dp);
        }
        
        return dp[i][j]=max(f(i+1,j,text1,text2,dp),f(i,j+1,text1,text2,dp));
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        //2 pal ka aram de
        //lets try tabulations first
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       //ok recursion not gonna work sad xD
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
};