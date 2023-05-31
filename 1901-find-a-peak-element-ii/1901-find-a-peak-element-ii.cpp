class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0, endCol = mat[0].size()-1;
        
        while(startCol <= endCol){
            int maxRow = 0, midCol = startCol + (endCol-startCol)/2;
            
            for(int row=0; row<mat.size(); row++){
                maxRow = mat[row][midCol] >= mat[maxRow][midCol]? row : maxRow;   
            }
            
            bool leftIsBig    =   midCol-1 >= startCol  &&  mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool rightIsBig   =   midCol+1 <= endCol    &&  mat[maxRow][midCol+1] > mat[maxRow][midCol];
            
            if(!leftIsBig && !rightIsBig)          // we have found the peak element
                return vector<int>{ maxRow, midCol};
            
            else if(rightIsBig) // if rightIsBig, then there is an element in 'right' that is bigger than all the elements in the 'midCol', 
                startCol = midCol+1;    //so 'midCol' cannot have a 'peakPlane'
            
            else // leftIsBig
                endCol = midCol-1;
        }
        return vector<int>{-1,-1};
    }
};