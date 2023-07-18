class Solution {
public:
    
    int f(int idx,string &s,unordered_map<string,int>mp,vector<int>&dp){
        if(idx==s.size()){
            return 1;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string temp="";
        for(int i=idx;i<s.size();++i){
            temp+=s[i];
            if(mp.find(temp)!=mp.end()){
                if(f(i+1,s,mp,dp)==1){
                    return dp[idx]=1;
                }
            }
        }
        return dp[idx]=0;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        
        unordered_map<string,int>mp;
        for(int i=0;i<wordDict.size();++i){
            mp[wordDict[i]]++;
        }
        
        return f(0,s,mp,dp);
    }
};