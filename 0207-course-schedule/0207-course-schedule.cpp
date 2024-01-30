class Solution {
public:
    
    bool isCycle(int node,vector<int>adj[],vector<int>&visited,vector<int>&path){
        visited[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(visited[it]==0){
                //aha
                if(isCycle(it,adj,visited,path)){
                    return true;
                }
            }
            else if(visited[it]==1 && path[it]==1){
                //SAME cycle BC.
                return true;
            }
        }
        
        path[node]=0;
        
        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        
        for(int i=0;i<numCourses;++i){
            if(visited[i]==0){
                //hm potential noice
                if(isCycle(i,adj,visited,path)){
                    return false;
                }
            }
        }
        
        return true; //nO Cycles Gotemm
        
    }
};