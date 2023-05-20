class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&visited,vector<int>&path,vector<int>&safe){
        visited[node]=1;
        path[node]=1;
        
        for(auto it:graph[node]){
            if(visited[it]==0 && dfs(it,graph,visited,path,safe)){
                safe[node]=0; //not safe sed
                return true;
            }
            else if(visited[it]==1 && path[it]==1){
                //ccycle fuck
                safe[node]=0;
                return true;
            }
        }
        
        safe[node]=1; //no cycle xD
        path[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //basically detect cycle with a little twist an extra safe array i suppose hm
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>path(n,0);
        vector<int>safe(n,1); //all safe currently
        
        for(int i=0;i<n;++i){
            if(visited[i]==0){
                dfs(i,graph,visited,path,safe);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<n;++i){
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};