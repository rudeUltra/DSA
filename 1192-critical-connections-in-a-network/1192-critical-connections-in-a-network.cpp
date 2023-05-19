class Solution {
public:
    void dfs(int node,int count,vector<int>adj[],vector<int>&time,vector<int>&low,vector<vector<int>>&ans,vector<int>&vis,int parent){
        vis[node]=1; //mark visiited
        time[node]=count;
        low[node]=count; //currently assuming

        for(auto it:adj[node]){
            //exploring all nodes
            if(it==parent){
                continue;
            }
            if(vis[it]==0){
                dfs(it,count+1,adj,time,low,ans,vis,node);

                low[node]=min(low[node],low[it]);

                if(low[it]>time[node]){
                    //breaking bad xD you cant reach me sus! bridge spotted
                    ans.push_back({it,node});
                }
            }
            else{
                //already visited so cannot be a bridge because same component siu
                //get the minimum from child node
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
      //bridges siu
      vector<int>time(n); //to count no of steps to be reached
      vector<int>low(n);  //to count min guy in the component or the main guy to determine we can reach what nodes again
      
      //if i can reach 6 from 9 then obvs i can reach to 7,8th node because 9 is linked to 6 so i can comeback xD

      //simple dfs

      vector<int>adj[n];
      vector<vector<int>>ans;
      int count=1; //to count no of steps

      vector<int>vis(n,0);

      for(int i=0;i<connections.size();++i){
          adj[connections[i][0]].push_back(connections[i][1]);
          adj[connections[i][1]].push_back(connections[i][0]); //forming the graph
      }
      dfs(0,count,adj,time,low,ans,vis,-1);

      return ans;
    }
};