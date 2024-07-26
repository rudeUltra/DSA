class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //floyd warshall algorithm siu
        vector<vector<int>>matrix(n,vector<int>(n,1e5));

        for(int i=0;i<edges.size();++i){
            matrix[edges[i][0]][edges[i][1]]=edges[i][2]; //creating the matrix
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j){
                    matrix[i][j]=0;
                }
            }
        }

        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]); //try all intermediate nodes siuu
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        int count=INT_MAX;
        int ans=0;
        for(int i=0;i<n;++i){
            int current=0;
            for(int j=0;j<n;++j){
                if(i==j){
                    continue;
                }
                if(matrix[i][j]<=distanceThreshold){
                    current++;
                }

            }
            if(current<=count){
                count=current;
                ans=i;
            }
        }
        return ans;


    }
};