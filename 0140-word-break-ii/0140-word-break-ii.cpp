class Solution {
public:

    void solve(string &s,string temp,vector<string>&ans,unordered_map<string,int>&mp,int idx){
        if(idx==s.size()){
            temp.pop_back(); //remove last space
            ans.push_back(temp);
            return;
        }
        string temp2="";
        string temp4=temp;
        for(int i=idx;i<s.size();++i){
            temp2=temp2+s[i];
            if(mp.find(temp2)!=mp.end()){
                //hmm potential cut so do IT !
                string temp3=temp2+" ";
                temp=temp+temp3;
                solve(s,temp,ans,mp,i+1);
                temp=temp4; //backtrack
            }
        }
    } 
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_map<string,int>mp;
        for(int i=0;i<wordDict.size();++i){
            mp[wordDict[i]]++;
        }
        solve(s,"",ans,mp,0);
        return ans;

    }
};