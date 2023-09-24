class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(102);
        
        dp[0].resize(1);
        dp[0][0]=poured; //siu
        
        for(int i=1;i<=query_row;++i){
            dp[i].resize(i+1,0);
            for(int j=0;j<i;++j){
                double extra=dp[i-1][j]-1;
                if(extra>0){
                 dp[i][j]+=extra*(double)0.5;
                 dp[i][j+1]+=extra*(double)0.5;
                    
                }
               
            }
        }
        if(dp[query_row][query_glass]>1){
            return 1;
        }
        return dp[query_row][query_glass];
    }
};