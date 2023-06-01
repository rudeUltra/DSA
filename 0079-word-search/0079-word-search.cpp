class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

     bool dfs(int i,int j,vector<vector<char>>&board,string word,int k){
        
            if(k==word.size()){
            return true;
        }
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[k]){
            return false;
        }
        
    
        
        //4 way dfs
    
        //bruh basic dfs rule while exploring make yourself invisible so we dont return to the same place mark yourself visited!
        char temp=board[i][j];
        board[i][j]=',';
        
        bool x=dfs(i+1,j,board,word,k+1) || dfs(i-1,j,board,word,k+1) || dfs(i,j+1,board,word,k+1) || dfs(i,j-1,board,word,k+1);
        
        board[i][j]=temp;
        
        return x;
    }
};