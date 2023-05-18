class disjoint{
    public:
    vector<int>parent,size;
    
    //constructor
    disjoint(int n){
        parent.resize(n);
        size.resize(n,1);
        
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
    
    void union1(int x,int y){
        int par_x=find(x);
        int par_y=find(y);
        if(par_x==par_y){
            return; //already connected
        }
        
        if(size[par_x]>size[par_y]){
            //x is the bigger component so connect y to x
            parent[par_y]=par_x;
            size[par_x]=size[par_x]+size[par_y];
        }
        else{
            parent[par_x]=par_y;
            size[par_y]=size[par_y]+size[par_x];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        //make disjoint set class siu
        
        //make the connection and count the extra siu
        disjoint ds(n);
        int extra=0;
        for(int i=0;i<connections.size();++i){
            int x=connections[i][0];
            int y=connections[i][1];
            
            if(ds.find(x)==ds.find(y)){
                extra++;
            }
            else{
                ds.union1(x,y);
            }
        }
        int components=0;
        for(int i=0;i<n;++i){
            if(ds.parent[i]==i){
                components++;
            }
        }
        
        if(extra>=components-1){
            return components-1;
        }
        
        return -1;
    }
};