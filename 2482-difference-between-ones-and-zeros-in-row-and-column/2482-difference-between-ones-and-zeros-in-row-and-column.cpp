class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        //Isn't this same hm
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int>rows(n,0);
        vector<int>cols(m,0);
        vector<int>rows0(n,0);
        vector<int>cols0(m,0);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    rows[i]++;
                    cols[j]++;
                }
                else{
                    rows0[i]++;
                    cols0[j]++;
                }
            }
        }
        
        
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
             
                grid[i][j]=rows[i]+cols[j]-rows0[i]-cols0[j];
            }
            
        }
        
        return grid;
    }
};