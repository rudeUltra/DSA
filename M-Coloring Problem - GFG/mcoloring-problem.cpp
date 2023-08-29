//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int node,bool graph[][101],int n,vector<int>&colors,int col){
        for(int i=0;i<n;++i){
            //Check each adj
            if(i!=node && graph[node][i]==1 && colors[i]==col){
                return false;
            }
        }
        
        return true;
    }
    bool f(int node,bool graph[][101],int m,int n,vector<int>&colors){
        if(node==n){
            return true; //All nodes coloured siu
        }
        for(int i=1;i<=m;++i){
            //Try out all colours
            colors[node]=i;
            if(isSafe(node,graph,n,colors,i) && f(node+1,graph,m,n,colors)){
                return true;
            }
            //nvm
            colors[node]=0;
        }
        return false;
    }
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        //Go with node by node and try all possiblities
        //bRuh
        vector<int>colors(n,0); //BAsically glorified visited array siu
        return f(0,graph,m,n,colors);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends