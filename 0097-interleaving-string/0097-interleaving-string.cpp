class Solution {
public:
    
    bool f(int i,int j,int k,string s1,string s2,string s3,vector<vector<vector<int>>>&dp){
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            //HmMM SALam alekum
            return true;
        }
        if(i==s1.size() && j==s2.size() && k<s3.size()){
            return false; //sed
        }
        
        if(k==s3.size()){
            return false;
        }
        
        
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        if(s3[k]==s1[i] && s3[k]==s2[j]){
            return dp[i][j][k]=f(i+1,j,k+1,s1,s2,s3,dp) | f(i,j+1,k+1,s1,s2,s3,dp);
        }
        
        if(s3[k]==s1[i]){
            return dp[i][j][k]=f(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s3[k]==s2[j]){
            return dp[i][j][k]=f(i,j+1,k+1,s1,s2,s3,dp);
        }
        
        return dp[i][j][k]=false; //no match fuk u bix Xd
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        int k=s3.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        
        //3d dp siu
        return f(0,0,0,s1,s2,s3,dp);
    }
};