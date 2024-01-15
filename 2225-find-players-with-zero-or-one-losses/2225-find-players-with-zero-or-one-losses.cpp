class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>winners;
        vector<int>losers;
        
        int n=matches.size();
        
        unordered_map<int,int>mp;
        unordered_map<int,int>visited;
        for(int i=0;i<n;++i){
            mp[matches[i][1]]++;
        }
        
        for(int i=0;i<n;++i){
            if(mp[matches[i][1]]==1 && visited[matches[i][1]]==0){
                losers.push_back(matches[i][1]);
                visited[matches[i][1]]=1;
            }
            if(mp[matches[i][0]]==0 && visited[matches[i][0]]==0){
                //undefeated Khobib sed
                winners.push_back(matches[i][0]);
                visited[matches[i][0]]=1;
                
            }
            
        }
        
        sort(winners.begin(),winners.end());
        sort(losers.begin(),losers.end());
        vector<vector<int>>ans;
        ans.push_back(winners);
        ans.push_back(losers);
        
        return ans;
        
        
    }
};