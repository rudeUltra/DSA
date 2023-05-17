class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        vector<vector<int>>dist(n,vector<int>(m,-1));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                dist[i][j]=INT_MAX;
            }
        }
        dist[0][0]=0; //dist matrix represents the effort hm
        
        pq.push({0,{0,0}});
        
        vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!pq.empty()){
            auto curr=pq.top();
            int curr_dist=curr.first;
            int x=curr.second.first;
            int y=curr.second.second;
            pq.pop();
            
            
            for(auto it:direction){
                int new_x=x+it[0];
                int new_y=y+it[1];
                
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m){
                    int new_effort=max(curr_dist,abs(heights[new_x][new_y]-heights[x][y]));
                    if(dist[new_x][new_y]>new_effort){
                        //we want min so siu
                        dist[new_x][new_y]=new_effort;
                        pq.push({dist[new_x][new_y],{new_x,new_y}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
        
        
    }
};