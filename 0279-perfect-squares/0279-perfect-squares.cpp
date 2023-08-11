class Solution {
    vector<int>dp;
public:
    int numSquares(int n) {
        for(int i=0;i<n+1;++i){
            dp.push_back(-1);
        }
        int ans1=n;
        int ans=solve(n,ans1);
        return ans;
    }
    int solve(int n,int ans1){
        if(n<=3){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=1;i*i<=n;++i){
            ans1=min(ans1,1+solve(n-i*i,ans1));
        }
        dp[n]=ans1;
        return ans1;
        
    }
};