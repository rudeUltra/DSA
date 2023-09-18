class Solution {
public:
        bool isCycle(int node,vector<int>adj[],vector<int>&visited,vector<int>&path,stack<int>&st){
        visited[node]=1;
        path[node]=1;
        
        for(auto it:adj[node]){
            if(visited[it]==0 && isCycle(it,adj,visited,path,st)){
                return true;
            }
            else if(visited[it]==path[it]){
                //SUS
                return true;
            }
        }
        path[node]=0;
        st.push(node); //gotteEMM
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //TOPO SORT SIU
        vector<int>visited(numCourses,0);
        vector<int>adj[numCourses];
        vector<int>path(numCourses,0);
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<prerequisites.size();++i){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //Making the connections for a directed graph siu
        
        for(int i=0;i<numCourses;++i){
            if(visited[i]==0 && isCycle(i,adj,visited,path,st)){
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