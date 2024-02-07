class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        
        int row_start=0;
        int row_end=n-1;
        int col_start=0;
        int col_end=n-1;
        int counter=1;
        while(row_start<n && row_end>=0 && col_start<n && col_end>=0){
            //first row
            for(int i=col_start;i<=col_end;++i){
                ans[row_start][i]=counter;
                counter++;
            }
            row_start++;
            if(row_start>row_end){
                break;
            }
            
            //last column
            for(int i=row_start;i<=row_end;++i){
                ans[i][col_end]=counter;
                counter++;
            }
            col_end--;
            
            if(col_start>col_end){
                break;
            }
            
            //last row
            
            for(int i=col_end;i>=col_start;--i){
                ans[row_end][i]=counter;
                counter++;
            }
            row_end--;
            
             if(row_start>row_end){
                break;
            }
            
            
            //last column
            
            for(int i=row_end;i>=row_start;--i){
                ans[i][col_start]=counter;
                counter++;
            }
            col_start++;
            
            if(col_start>col_end){
                break;
            }
        }
        
        return ans;
    }
};