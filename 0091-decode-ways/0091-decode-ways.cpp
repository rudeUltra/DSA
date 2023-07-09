class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,0);
        return dfs(0,s,dp);
    }
    int dfs(int i,string s,vector<int>&dp){
        if(s[i]=='0'){
            return 0; //not valid 06 
        }
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=0){
            return dp[i];
        }
        int x=dfs(i+1,s,dp); //take single element
        int y=0;
        if(i+1<s.size() && ((s[i]=='1') || ((s[i]=='2') &&  s[i+1]<'7') )){
            y=dfs(i+2,s,dp);
        }
        dp[i]=x+y;
         return dp[i];
    }
};