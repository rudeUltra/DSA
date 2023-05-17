//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //adh list already given so no need to build it hm
        vector<int>dist(V);
        for(int i=0;i<V;++i){
            dist[i]=INT_MAX;
        }
        dist[S]=0;
        
        //min heap hm
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0,S});
        //remmeber sorted using 1 value so put distance there hm
        while(!pq.empty()){
            int node=pq.top().second;
            int curr=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it[0];
                int distance=it[1];
                
                if(curr+distance<dist[adjnode]){
                    //update
                    dist[adjnode]=curr+distance;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends