class Solution {
public:
    
    int f(int idx,string &s,unordered_map<string,int>&mp,vector<int>&dp){
        if(idx==s.size()){
            return 0; //No more 
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int ans=1e5;
        string temp="";
        for(int i=idx;i<s.size();++i){
            //Think of idx as the starting point siu
            temp+=s[i];
            int cost=(i-idx)+1;;
            if(mp.find(temp)!=mp.end()){
                cost=0;
            }
            ans=min(ans,f(i+1,s,mp,dp)+cost);
        }
        return dp[idx]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        //lets think like Palindrome partition now siu
        //If match then 0 else siu 
        int n=dictionary.size();
        vector<int>dp(s.size(),-1);
        unordered_map<string,int>mp;
        for(int i=0;i<n;++i){
            mp[dictionary[i]]++;
        }
        
        
        return f(0,s,mp,dp);
    }
};