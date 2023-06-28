class Solution {
public:
    
    bool f(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i<0 && j<0){
            //siuuu 
            return 1;
        }
        if(i<0 && j>=0){
            while(j>=0){
                if(p[j]!='*'){
                    return 0;
                }
                j--;
            }
            return 1;
        }
        
        if(j<0){
            return 0; //no chance of matching sed
        }
        
         if(dp[i][j]!=-1){
            return dp[i][j];
         }
        
        
        
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }
        
        if(p[j]=='*'){
            //2 options siuu
            return dp[i][j]=f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);
        }
        
        return 0; //no match bc bhak xD
    }
    
    
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return f(n-1,m-1,s,p,dp);
    }
};