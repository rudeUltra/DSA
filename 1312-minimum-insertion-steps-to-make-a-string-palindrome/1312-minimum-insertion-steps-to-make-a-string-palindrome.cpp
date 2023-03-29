class Solution {
public:
    int minInsertions(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        
        int n=s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(s[i-1]==temp[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //try all possibilities
                }
            }
        }
        int no_of_same=dp[n][n]; //reversed string same size obvs
        
        return n-no_of_same;
    }
};