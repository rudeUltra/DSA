class Solution {
public:
    class Disjoint{
        public:
        vector<int>parent;
        vector<int>rank;
        
        Disjoint(int n){
            //Constructor
            rank.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;++i){
                parent[i]=i; //Siu
            }
        }
        
        int find(int node){
            if(parent[node]==node){
                return node;
            }
            
            return parent[node]=find(parent[node]);
        }
        
        bool Union(int x,int y){
            int u=find(x);
            int v=find(y);
            
            if(u==v){
                return false;
            }
            
            if(rank[u]>rank[v]){
                //U will be the main node
                parent[v]=u;
                rank[u]=rank[u]+rank[v];
            }
            else{
                parent[u]=v;
                rank[v]=rank[v]+rank[u];
            }
            return true; //merged siu
        }
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        Disjoint ds(n);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                pq.push({dist,{i,j}});
            }
        }
        
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            
            int dist=it.first;
            int x=it.second.first;
            int y=it.second.second;
            
            if(ds.Union(x,y)){
                ans+=dist;
            }
        }
        return ans;
    }
};