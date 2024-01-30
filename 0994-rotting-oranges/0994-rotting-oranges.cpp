class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        int fresh_count=0;
        int rotten_count=0;
        
        queue<pair<int,int>>pq;
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    fresh_count++;
                }
                else if(grid[i][j]==2){
                    //Multi source BFS HM nOice
                    rotten_count++;
                    pq.push({i,j});
                }
            }
        }
        if(fresh_count==0){
            return 0;
        }
        
        if(rotten_count==0){
            //BC
            return -1;
        }
        int timer=0;
        
        while(!pq.empty()){
            int k=pq.size(); //level order type Noice
            
            if(fresh_count==0){
                return timer;
            }
            
            for(int i=0;i<k;++i){
                auto it=pq.front();
                pq.pop(); 
                
                int x=it.first;
                int y=it.second; 
                
                //See can I contribute hM.
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                
                for(int j=0;j<4;++j){
                    int new_x=x+dx[j];
                    int new_y=y+dy[j];
                    
                    if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && grid[new_x][new_y]==1){
                        //goteemm fresh orange Siu
                        fresh_count--;
                        grid[new_x][new_y]=2;
                        pq.push({new_x,new_y});
                    }
                }
                
            }
            timer++;
        }
        
        return -1;
    }
};