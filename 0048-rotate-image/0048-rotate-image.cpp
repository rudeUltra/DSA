class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //first transpose then reverse each row
        int n=matrix.size();
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                //swap
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //reverse each row
        for(int i=0;i<n;++i){
            int l=0;
            int r=n-1;
            while(l<r){
                 int temp=matrix[i][l];
                matrix[i][l]=matrix[i][r];
                matrix[i][r]=temp;
                ++l;
                --r;
            }
        }
    }
};