class Solution {
public:
    bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&path){
        visited[node]=1;
        path[node]=1;
        
        for(auto it : adj[node]){
            if(visited[it]==0){
                if(dfs(it,adj,visited,path)==1){
                    return true;
                }
            }
            else if(visited[it]==1 && path[it]==1){
                return true;
            }
        }
        
        path[node]=0;
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //directed graph cycle detection sIUU
        int n=prerequisites.size();
        vector<int>adj[numCourses];
        
        for(int i=0;i<n;++i){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        for(int i=0;i<numCourses;++i){
            if(visited[i]==0){
                if(dfs(i,adj,visited,path)==1){
                    return false;
                }
            }
        }
        
        return true; //no cycle siu
    
    }
};