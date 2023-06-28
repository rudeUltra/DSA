class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans=0;
        //simple dfs ? hm might not work so u know what lets go with djksta siu
        vector<pair<int,double>>adj[n];
        
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double>dist(n,0);
        dist[start]=1;
        
        //max heap xD we find max path not minimum
        priority_queue<pair<double,int>>pq; //max heap
        
        pq.push({1.0,start});
        
        while(!pq.empty()){
            auto it=pq.top();
            double distance=it.first;
            int node=it.second;
            pq.pop();
            
            for(auto it1:adj[node]){
                //explore neighbors
                cout<<it1.second<<" ";
                if(distance*it1.second>dist[it1.first]){
                    dist[it1.first]=it1.second*distance;
                    pq.push({dist[it1.first],it1.first});
                }
            }
        }
        
        return dist[end];
    }
};