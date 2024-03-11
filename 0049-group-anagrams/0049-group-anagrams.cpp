class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        
        map<vector<int>,vector<string>>mp;
        
        for(int i=0;i<n;++i){
            vector<int>hash(26,0);
            for(int j=0;j<strs[i].size();++j){
                hash[strs[i][j]-'a']++;
            }
            mp[hash].push_back(strs[i]);
        }
        
        for(auto it:mp){
            auto vec=it.first;
            
            vector<string>temp;
            for(auto it1:it.second){
                temp.push_back(it1);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
        
        
        
    }
};