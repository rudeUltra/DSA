class Solution {
public:
    //try all possibilities siu
   unordered_map<char,string>mp;
    void f(string digits,string &temp,vector<string>&ans,int index){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        string curr=mp[digits[index]];
        for(int i=0;i<mp[digits[index]].size();++i){
            temp.push_back(curr[i]);
            f(digits,temp,ans,index+1);
            temp.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        //backtracking solution interesting
         
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";

        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string temp=""; //temp string
        f(digits,temp,ans,0);

        return ans;
    }
};