class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //Siu
        vector<vector<int>>dp(rowIndex+1);
        
        for(int i=0;i<=rowIndex;++i){
            dp[i].resize(i+1,0);
            
            dp[i][0]=1;
            dp[i][i]=1;
            
            for(int j=1;j<i;++j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
            }
            
        }
        return dp[rowIndex];
    }
};