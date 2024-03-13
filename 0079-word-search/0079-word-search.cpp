class Solution {
public:
    
    
    
    
    bool dfs(int idx,int i,int j,vector<vector<char>>&board,string word,vector<vector<int>>&visited){
        if(idx==word.size()){
            //less Goo
            return true;
        }
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || word[idx]!=board[i][j] || visited[i][j]==1){
            return false; //Moy6e Moye
        }
        
        visited[i][j]=1; //ahA
        
        bool down=dfs(idx+1,i+1,j,board,word,visited);
        bool right=dfs(idx+1,i,j+1,board,word,visited);
        bool left=dfs(idx+1,i,j-1,board,word,visited);
        bool up=dfs(idx+1,i-1,j,board,word,visited);
        
        if(down || right || left || up){
            return true;
        }
        
        //Maa chuda...
        visited[i][j]=0;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        
        //Before each call make a visited nOice
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                    //nOICE
                    vector<vector<int>>visited(n,vector<int>(m+1,0));
                    
                    if(dfs(0,i,j,board,word,visited)){
                        return true;
                    }
                }
            }
        }
        
        return false; //nahi MilA F.
        
    }
};