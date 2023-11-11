class Graph {
public:
    vector<pair<int,int>>adj[102];
    int n1;
    Graph(int n, vector<vector<int>>& edges) {
        n1=n;
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(n1+1,1e9);
        dist[node1]=0; //source;
         priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,node1});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        //dJKSTRA algo
        if(dist[node2]==1e9){
            return -1;
        }
        return dist[node2];
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */