class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mp;
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;++i){
            mp[s[i]]++;
        }
        for(int i=0;i<m;++i){
            if(mp[t[i]]==0){
                //fuck.
                return false;
            }
            mp[t[i]]--;
        }
        
        return true;
    }
};