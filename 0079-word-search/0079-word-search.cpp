class Solution {
public:
    
    
    
    bool dfs(int i,int j,vector<vector<char>>&board,string &word,int idx,vector<vector<int>>&visited){
        
         if(idx==word.size()){
            return true; //all Matched
        }
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]==1 || board[i][j]!=word[idx]){
            return false;
        }
        
      
        
        visited[i][j]=1; //Hm.
        
        bool up=dfs(i-1,j,board,word,idx+1,visited);
        bool down=dfs(i+1,j,board,word,idx+1,visited);
        bool right=dfs(i,j+1,board,word,idx+1,visited);
        bool left=dfs(i,j-1,board,word,idx+1,visited);
        
        if(up || down || right || left){
            return true;
        }
        
        //sed so Backtrack
        visited[i][j]=0;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                    //AHA possible starting point for DFS noice
                    vector<vector<int>>visited(n,vector<int>(m,0));
                    if(dfs(i,j,board,word,0,visited)){
                        return true;
                    }
                }
            }
        }
        return false; //nahi mIla sad
    }
};