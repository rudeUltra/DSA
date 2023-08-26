class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int>dp(n,1);
        if(n==1){
            return 1;
        }
        int ans=1;
        //LIS pattern Siu
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(dp[i],ans);
                }
            }
        }
        
        return ans;
    }
};