class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int count=1;
        
        for(int i=0;i<n;++i){
            
            if(mp[s[i]]==1){
                cout<<s[i]<<" ";
                //interesting
                count++;
                mp.clear();
            }
            
            mp[s[i]]++;
        }
        
        return count;
    }
};