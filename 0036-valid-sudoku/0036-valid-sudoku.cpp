class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        int rows[9][9]={-1};
        int cols[9][9]={-1};
        int boxes[9][9]={-1};
        
        
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    num--; //to fit in the array hm.
                    if(rows[i][num]==1){
                        return false;
                    }
                    rows[i][num]=1;
                    if(cols[j][num]==1){
                        return false;
                    }
                    cols[j][num]=1;
                    
                    if(boxes[i/3*3+j/3][num]==1){
                        return false;
                    }
                    boxes[i/3*3+j/3][num]=1;
                    
                }
                //check all boxes hm
            }
        }
        return true;
    }
};