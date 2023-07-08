class disjoint{
    public:
    vector<int>parent;
    vector<int>rank;
    
    disjoint(int n){
        parent.resize(n);
        rank.resize(n,1);
        
        for(int i=0;i<n;++i){
            parent[i]=i; //self parent
        }
        
    }
    
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    void join(int x,int y){
        int u=find(x);
        int v=find(y);
        
        if(u==v){
            return;
        }
        else if(rank[u]>rank[v]){
            //x bigger less goo
            rank[u]=rank[u]+rank[v];
            parent[v]=u;
        }
        else{
            rank[v]=rank[u]+rank[v];
            parent[u]=v;
        }
    }
};


class Solution {
public:
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        //tree means no cycles and a single component sUI
        disjoint ds(n);
        
        for(int i=0;i<n;++i){
            int x=edges[i][0];
            int y=edges[i][1];
            
            if(ds.find(x-1)==ds.find(y-1)){
                //cycle BC 
                return edges[i];
            }
            ds.join(x-1,y-1);
        }
        return {};
        
    }
};