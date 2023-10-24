class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //Entire matrix is sorted for normal BS we just have to convert co-ordinates to indexes
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        //Solve 1 problem at a time not the entire problem itself siu
        
        int low=0;
        int high=(n*m)-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int row=mid/m;
            int col=mid%m;
            
            //No need to plus we are doing i,j Bruh
            
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return false;
    }
};