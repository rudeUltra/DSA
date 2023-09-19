class Solution {
public:
    
    int f(int idx,string &s,vector<int>&dp){
        if(idx>=s.size()){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int one=f(idx+1,s,dp);
        int two=0;
        if(s[idx]=='1' || s[idx]=='2'){
            if(idx<s.size()-1 && s[idx]=='1'){
                two=f(idx+2,s,dp);
            }
            else if(idx<s.size()-1 && s[idx]=='2' && s[idx+1]<='6'){
                two=f(idx+2,s,dp);
            }
        }
        
        return dp[idx]=one+two;
    }
    
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        
        return f(0,s,dp);
    }
};