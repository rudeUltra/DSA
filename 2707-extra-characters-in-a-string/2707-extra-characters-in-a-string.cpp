class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        
        //siu
        vector<int>dp(n+2,0); //for string
        
        if(s.length()<1){
            return 0;
        }
        
        for(int i=1;i<=n;++i){
            dp[i]=dp[i-1]+1;
            
            for(auto it:dictionary){
                
                if(i>=it.length()){
                    //match found
                    if(s.substr(i-it.length(),it.length())==it){
                        int k=i-it.length();
                    dp[i]=min(dp[i],dp[k]);
                    }
                }
            }
        }
        return dp[n];
    }
};