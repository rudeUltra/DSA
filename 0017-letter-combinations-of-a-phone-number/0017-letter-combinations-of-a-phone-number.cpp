class Solution {
public:
    
    void f(int idx,string digits,string temp,vector<string>&ans,unordered_map<char,string>mp){
        if(idx==digits.size()){
            ans.push_back(temp);
            return;
        }
        string curr=mp[digits[idx]];
        
        for(int i=0;i<curr.size();++i){
            f(idx+1,digits,temp+curr[i],ans,mp);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        //For each index we have m options explore them all Siu
        //Apna dhalo na baaki apna dekh lenge xD
        string temp;
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        
        f(0,digits,temp,ans,mp);
        
        return ans;
        
    }
};