class Solution {
public:
    bool dfs(int node,int color,vector<int>&vis,vector<int>adj[]){
        //vis array will hold the color
        vis[node]=color;
        for(auto it:adj[node]){
            if(vis[it]==-1){
                if(!dfs(it,!color,vis,adj)){
                    return false;
                }
            }
            else{
                //already visited must be a parent so chekc parents color/value
                if(vis[it]==vis[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //convert adjacency matrix to adjacency list hm.
        int n=graph.size();
        vector<int>vis(n,-1); //initially all color -1
        vector<int>adj[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<graph[i].size();++j){
                adj[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<n;++i){
            //0 based indexing
            if(vis[i]==-1){
                if(!dfs(i,1,vis,adj)){
                    return false; //initial color is -1
                }
            }
        }
        return true;
        
    }
};