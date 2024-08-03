class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i){
            mp[target[i]]++;
        }
        
        for(int i=0;i<n;++i){
            if(mp[arr[i]]==0){
                return false;
            }
            mp[arr[i]]--;
        }
        
        return true;
        
        
    }
};