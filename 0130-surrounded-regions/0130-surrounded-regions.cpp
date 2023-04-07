class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>>&board,vector<vector<char>>&temp){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O'){
            return;
        }
        board[i][j]='A';
        
        dfs(i-1,j,board,temp);
        dfs(i+1,j,board,temp);
        dfs(i,j-1,board,temp);
        dfs(i,j+1,board,temp);
        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        //check all corners left ,down ,up,right
        
        vector<vector<char>>temp(n,vector<char>(m,'B'));
        
        for(int i=0;i<n;++i){
            if(board[i][0]=='O'){
                dfs(i,0,board,temp);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,temp);
            }
        }
        
        for(int i=0;i<m;++i){
            if(board[0][i]=='O'){
                dfs(0,i,board,temp);
            }
            
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,temp);
            }
        }
        
        
        //all unowrthy 0s converted xD so all 0s will be converted to X
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
            }
        }
        
        
    }
};