class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int n=edges.size();
        
        for(int i=0;i<n;++i){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
        }
        for(auto it:mp){
            if(it.second == n){
                return it.first;
            }
        }
        return 0;
    }
};