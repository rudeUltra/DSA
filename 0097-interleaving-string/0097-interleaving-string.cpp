class Solution {
public:
    
    bool f(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            //Gotemm
            return true;
        }
        if(k==s3.size()){
            //are Bahinchod
            return false;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            //siu two option huh
            return dp[i][j][k]=f(i+1,j,k+1,s1,s2,s3,dp) | f(i,j+1,k+1,s1,s2,s3,dp);
        }
        else if(s1[i]==s3[k]){
            return dp[i][j][k]=f(i+1,j,k+1,s1,s2,s3,dp);
        }
        else if(s2[j]==s3[k]){
            return dp[i][j][k]=f(i,j+1,k+1,s1,s2,s3,dp);
        }
        
        return dp[i][j][k]=false; //Koi match hi nahi hai bhai..sed
        
        
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
        return f(0,0,0,s1,s2,s3,dp);
    }
};