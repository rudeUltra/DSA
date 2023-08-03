class Solution {
public:
    
    void dfs(int idx,string digits,string &temp,vector<string>&ans,unordered_map<char,string>mp){
        if(idx>=digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto it:mp[digits[idx]]){
            temp.push_back(it);
            dfs(idx+1,digits,temp,ans,mp);
            temp.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        int n=digits.size();
        
       
        
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        string temp;
        vector<string>ans;
         if(n==0){
            return ans;
        }
        
        dfs(0,digits,temp,ans,mp);
        
        return ans;
    }
};