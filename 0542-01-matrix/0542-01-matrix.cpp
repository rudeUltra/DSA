class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        //should i put 1 or 0 in the matrix hm
        vector<vector<int>>dist(n,vector<int>(m,1e5));
        
        //basically can i help plus ok i helped this guy can this guy help others siu
        queue<pair<int,int>>pq;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    pq.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        vector<int>x{-1,0,1,0};
        vector<int>y{0,1,0,-1};
        //multiple starting points hm siu
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            
            //four directions
            int x1=it.first;
            int y1=it.second;
            
            for(int i=0;i<4;++i){
                int new_x=x1+x[i];
                int new_y=y1+y[i];
                
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m){
                    if(dist[x1][y1]+1<dist[new_x][new_y]){
                        //I can help siu
                        dist[new_x][new_y]=1+dist[x1][y1];
                        pq.push({new_x,new_y});
                    }
                }
            }
        }
        
        return dist;
        
    }
};