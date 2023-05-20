class Solution {
public:
    
    bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&path){
        vis[node]=1; //siu
        path[node]=1;
        
        for(auto it:adj[node]){
            if(vis[it]==0){
                //not visited
                if(dfs(it,adj,vis,path)==true){
                    return true;
                }
            }
            else if(vis[it]==1 && path[it]==1){
                return true;
            }
        }
        
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //basically detect cycles siu in a directed graph
        
        //if we are in a loo/cycle obvs we can never finish all courses because deadlock condition
        
        vector<int>adj[numCourses];
        
        int n=prerequisites.size();
        
        for(int i=0;i<n;++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //mai kyaa karu mai kyaaa karu :)
        
        vector<int>vis(numCourses,0);
        vector<int>path(numCourses,0);
        for(int i=0;i<numCourses;++i){
            if(dfs(i,adj,vis,path)==true){
                return false;
            }
        }
        
        return true; // no cycle we can complete siu
        
        
    }
};