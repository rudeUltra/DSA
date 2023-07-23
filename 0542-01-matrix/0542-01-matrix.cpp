class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,-1));
        queue<pair<int,int>> Q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    Q.push({i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!Q.empty()){
            pair<int,int> current=Q.front();
            Q.pop();
            for(int i=0;i<4;++i){
                pair<int,int> neighbor={current.first+dx[i],current.second + dy[i]};
                if(neighbor.first>=0 && neighbor.first<n && neighbor.second>=0 && neighbor.second<m && dis[neighbor.first][neighbor.second]==-1){
                    dis[neighbor.first][neighbor.second]=dis[current.first][current.second]+1;
                    Q.push({neighbor.first,neighbor.second});
                }
            }
        }
        return dis;
        
    }
};