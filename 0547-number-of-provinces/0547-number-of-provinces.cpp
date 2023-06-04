class disjoint{
    public:
  vector<int>parent,rank;
    disjoint(int n){
        parent.resize(n);
        rank.resize(n,1);
        
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
    }
    int findparent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findparent(parent[node]);
    }
    void union1(int x,int y){
        int u=findparent(x);
        int v=findparent(y);
        
        if(u==v){
            //same parent meaning same component 
            return;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
            rank[u]=rank[u]+rank[v];
        }
        else{
            parent[u]=v;
            rank[v]=rank[v]+rank[u];
        }
    }
};



class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        disjoint ds(n);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<isConnected[i].size();++j){
                if(i!=j && isConnected[i][j]==1){
                    ds.union1(i,j);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;++i){
            //find no of components
            if(ds.parent[i]==i){
                count++;
            }
        }
        
        return count;
    }
};