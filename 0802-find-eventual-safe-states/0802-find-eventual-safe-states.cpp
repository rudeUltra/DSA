class Solution {
public:
    
    bool dfs(int node,vector<int>&visited,vector<int>&path,vector<int>&ans,vector<int>adj[]){
        visited[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(dfs(it,visited,path,ans,adj)==false){
                    return false; //any child returning false sed
                }
            }
            else if(visited[it]==1 && path[it]==1){
                //cycle sed
                return false;
            }
        }
        
        path[node]=0;
        ans.push_back(node);
        return true;
    }
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //cycle edit hm
        int n=graph.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;++i){
            int m=graph[i].size();
            for(int j=0;j<m;++j){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        vector<int>ans;
        vector<int>visited(n,0);
        vector<int>path(n,0); 
        
        //there should be no cycles siu
        
        for(int i=0;i<n;++i){
            if(visited[i]==0){
                dfs(i,visited,path,ans,adj);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};