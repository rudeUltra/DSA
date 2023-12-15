class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int>mp;
        
        for(int i=0;i<paths.size();++i){
            mp[paths[i][0]]=1;
        }
        
        for(int i=0;i<paths.size();++i){
            if(mp[paths[i][1]]==0){
                return paths[i][1];
            }
        }
        
        return "";
        
        
    }
};