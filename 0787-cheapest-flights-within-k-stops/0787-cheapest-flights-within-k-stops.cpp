class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Trick here is to minimise stops and Distance WOoOoH
        //Build the graph
        
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<flights.size();++i){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        
        vector<int>dist(n,INT_MAX);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,{src,0}});
        dist[src]=0; //to reach here nothing required sir Xd
        
        while(!pq.empty()){
            auto it=pq.top();
            int curr=it.first;
            int node=it.second.first;
            int distance=it.second.second;
            pq.pop();
            
            if(curr>k){
                //gone cant siu
                continue;
            }
            //big Logic about this question is the No of steps plus edit logic OOh
            
            curr++;
            
            for(auto it1:adj[node]){
                int adj=it1.first;
                int dist_to=it1.second;
                
                if(distance+dist_to<dist[adj]){
                    dist[adj]=distance+dist_to;
                    pq.push({curr,{adj,dist[adj]}});
                }
                
            }
        }
        
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
        
    }
};