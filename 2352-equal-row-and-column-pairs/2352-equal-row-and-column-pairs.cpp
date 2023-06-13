class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(); //n*n matrix siu
        
        vector<vector<int>>trans(n,vector<int>(n));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                trans[i][j]=grid[i][j];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                int temp=trans[i][j];
                trans[i][j]=trans[j][i];
                trans[j][i]=temp;
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                vector<int>temp1;
                for(int k=0;k<n;++k){
                    temp1.push_back(grid[j][k]);
                }
                if(temp1==trans[i]){
                    count++;
                }
            
                
            }
            
            
        }
        
        return count;
    }
};