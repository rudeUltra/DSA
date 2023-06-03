class Solution {
public:
    
    void dfs(int node,vector<int>&informTime,int time,int &mx,vector<int>adj[]){
        //no need of visited bcus tree structure
        mx=max(mx,time);
        
        for(auto it:adj[node]){
            dfs(it,informTime,time+informTime[node],mx,adj);
        }
    }
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //interesting way to create adjacency list remember its a tree top to bottom siu
        vector<int>adj[n];
        
        for(int i=0;i<n;++i){
            if(manager[i]!=-1){
                //root element basically siu
                //mera koi manager/boss nahi hai siUU elon musk
                adj[manager[i]].push_back(i); //2->1 2->3 ..like a tree structure
            }
        }
        int mx=0;
        dfs(headID,informTime,0,mx,adj);
        
        return mx;
    }
};