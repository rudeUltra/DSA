class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        unordered_map<char,int>hash;
        
        //Clear the map hm.
        for(int i=0;i<n;++i){
            mp[s[i]]=i;
        }
        vector<int>ans;
        int unique=0;
        int total=0;
        int prev=-1;
        for(int i=0;i<n;++i){
            hash[s[i]]++;
            if(hash[s[i]]==1){
                unique++;
            }
            if(i==mp[s[i]]){
                //last position hm
                total++;
            }
            
            if(unique==total){
                //nOice
                ans.push_back((i-prev));
                unique=0;
                total=0;
                prev=i;
                hash.clear();
            }
        }
        return ans;
    }
};