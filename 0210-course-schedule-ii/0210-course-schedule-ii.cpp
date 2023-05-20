class Solution {
public:
    //we are doing topo sort plus cycle detection in the same function siu
    
    bool cycle(int node,vector<int> adj[],vector<int>&path,vector<int>&visited,stack<int>&st){
        visited[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(visited[it]==0){
                if(cycle(it,adj,path,visited,st)){
                    return true;
                }
            }
            else if(visited[it]==1 && path[it]==1){
                //sed
                return true; //cycle
            }
        }
        
        path[node]=0;
        st.push(node);
        
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //topo sort + directed graph cycle detection siu
        
        if(numCourses==1 && prerequisites.size()==0){
           return {0}; //SIUU 
        }
        
        vector<int>ans; //to hold the topo sort 
        vector<int>visited(numCourses,0);
        
        vector<int>adj[numCourses];
        
        //build the graph
        
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>path(numCourses,0);
        stack<int>st; //for topo sort
        for(int i=0;i<numCourses;++i){
            //multiple components siu
            if(visited[i]==0 && cycle(i,adj,path,visited,st)){
                return {};
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};