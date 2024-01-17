class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        unordered_map<int,int>visited;
        
        for(int i=0;i<n;++i){
            mp[arr[i]]++;
        }
        
        for(auto it:mp){
            
            if(visited[it.second]!=0){
                return false;
            }
            visited[it.second]=1;
        }
        
        return true;
    }
};