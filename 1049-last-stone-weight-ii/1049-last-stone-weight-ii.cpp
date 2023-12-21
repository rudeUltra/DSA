class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        
        int sum=0;
        
        for(int i=0;i<n;++i){
            sum+=stones[i];
        }
        int x=(sum/2)+1;
        vector<vector<int>>dp(n+1,vector<int>(x,0));
        int target=0;
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=sum/2;++j){
                //two option pick or no pick
                
                dp[i][j]=dp[i-1][j]; //not pick
                
                if(j>=stones[i-1]){
                    dp[i][j]=dp[i-1][j] | dp[i-1][j-stones[i-1]];
                }
                
                if(dp[i][j]){
                    //Maximum possible sum hm
                    target=max(target,j);
                }
            }
        }
        
        return sum-2*target;
        
        
    }
};