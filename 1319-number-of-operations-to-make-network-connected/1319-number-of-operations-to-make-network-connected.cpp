class dsu{
    public:
    vector<int>parent,rank;
    
    dsu(int n){
        //siu
        rank.resize(n,1);
        parent.resize(n);
        
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
        
        //Self parent hm
    }
    
    int find(int node){
        if(parent[node]==node){
            return node;
        }
        
        return parent[node]=find(parent[node]);
    }
    
    void join(int x,int y){
        int x1=find(x);
        int x2=find(y);
        
        if(x1==x2){
            return;
        }
        
        if(rank[x1]>rank[x2]){
            parent[x2]=x1;
        }
        else{
            parent[x1]=x2;
        }
    }
};



class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        dsu ds(n);
        
        int extra=0;
        int components=0;
        
        for(int i=0;i<connections.size();++i){
            if(ds.find(connections[i][0])==ds.find(connections[i][1])){
                extra++;
            }
            else{
                ds.join(connections[i][0],connections[i][1]);
            }
        }
        for(int i=0;i<n;++i){
            if(ds.parent[i]==i){
                components++;
            }
        }
        cout<<components<<extra<<" ";
        if(components-1<=extra){
            return components-1;
        }
        
        return -1;
    }
};