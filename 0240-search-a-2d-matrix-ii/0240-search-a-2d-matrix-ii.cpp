class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //life doesnt stop nanu just keep going head high waiting for the next challenge 
        //This struggle is insane i love it :)
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int i=0;
        int j=m-1;
        
        while(i<n && j>=0){
            //Works because column and row are both sorted siu
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target){
                j--;
            }
            else{
                ++i;
            }
        }
        
        return false;
    }
};