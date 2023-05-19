class Solution {
public:
    
    bool f(int node,vector<vector<int>>&graph,vector<int>&color,int col){
        color[node]=col; //mark it visited
        bool x=true;
        for(auto it:graph[node]){
            if(color[it]==-1){
                //not visited go ahead dfs
                bool x=f(it,graph,color,1-col); //opposite color
                if(x==false){
                    return false; //just check the negative condition bix
                }
            }
            else if(color[it]!=-1){
                if(color[it]==color[node]){
                    //sus can't partition into 2 sets sed
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        //no need to convert into a adj list pretty straighforward hm
        int n=graph.size();
        vector<int>color(n,-1); //modified visited array hm
        
        //1-red 0-blue
        //there are multiple components sed
        
        for(int i=0;i<n;++i){
            if(color[i]==-1){
                if(!f(i,graph,color,1)){
                    return false;
                }
            }
        }
        
        return true;
    }
};