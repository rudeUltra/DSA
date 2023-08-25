class Solution {
public:
    int f(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return 1;
        }
        if(i==s1.size() && j==s2.size() && k<s3.size()){
            return 0; //sed
        }
        if(k==s3.size()){
            return 0;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            //2 options take from s1 or s2
            return dp[i][j][k]=f(i+1,j,k+1,s1,s2,s3,dp) | f(i,j+1,k+1,s1,s2,s3,dp);
        }
        if(s1[i]==s3[k]){
            return dp[i][j][k]=f(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s2[j]==s3[k]){
            return dp[i][j][k]=f(i,j+1,k+1,s1,s2,s3,dp);
        }
        
        return dp[i][j][k]=false; //Bruh no metch
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        //LCS pattern hm
        
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
        return f(0,0,0,s1,s2,s3,dp);
    }
};