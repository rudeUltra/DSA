//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	void topo(int node,vector<int>adj[],stack<int>&st,vector<int>&visited){
	    visited[node]=1;
	    
	    for(auto it:adj[node]){
	        if(visited[it]==0){
	            topo(it,adj,st,visited);
	        }
	    }
	    
	    //all done so push it onto the stack
	    
	    st.push(node); //siu
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    //since we are doing dfs we need ?? yes a VISITED array Boi
	    vector<int>visited(V,0);
	    //and a stack siu
	    stack<int>st;
	    vector<int>ans; //to store the ans siu
	    for(int i=0;i<V;++i){
	        if(visited[i]==0){
	            topo(i,adj,st,visited);
	        }
	    }
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends