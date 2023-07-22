class Solution {
public:
    double help(int r,int c,int n,int k,vector<vector<vector<double>>>&dp){
        if(r<0 || c<0 || r>=n || c>=n)return 0;
        if(k==0)return 1;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        int dx[8] = {2,2,-2,-2,1,1,-1,-1};
        int dy[8] = {1,-1,1,-1,2,-2,2,-2};
        double ans=0;
       for(int i=0;i<8;i++){
           ans += help(r+dx[i],c+dy[i],n,k-1,dp)/8;
        }
        return dp[r][c][k] = ans;
    }
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
       return help(r,c,n,k,dp); 
    }
};