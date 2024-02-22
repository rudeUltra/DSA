class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        vector<int>visited(n,0);
        int m=trust.size();
        
        if(m==0 && n==1){
            return 1;
        }
        
        for(int i=0;i<m;++i){
            visited[trust[i][0]-1]=1;
            mp[trust[i][1]]++;
        }
        
        for(auto it:mp){
            if(it.second==n-1 && visited[it.first-1]==0){
                return it.first;
            }
        }
        
        return -1;
    }
};