class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //Bhai bayern Come on...
        //Go Destination to source siu
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        
        queue<pair<int,int>>pq;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    //push
                    pq.push({i,j});
                    dist[i][j]=0;
                }
                
            }
        }
        
        //Bhaiiii god gave another lesson dont give 
        
       int dx[]={-1,0,1,0};
       int dy[]={0,1,0,-1};
        
        while(!pq.empty()){
            //No need to do level order
            auto it=pq.front();
            pq.pop();
            
            //CHeck 4 direction and see where can i help
            
            for(int i=0;i<4;++i){
                int new_x=it.first+dx[i];
                int new_y=it.second+dy[i];
                
                if(new_x>=0 && new_x<n && new_y>=0 && new_y<m){
                    if(dist[it.first][it.second]+1<dist[new_x][new_y]){
                        //Aha
                        dist[new_x][new_y]=1+dist[it.first][it.second];
                        pq.push({new_x,new_y});
                    }
                }
            }
            
        }
        
        
        return dist;
        
        
        
    }
};