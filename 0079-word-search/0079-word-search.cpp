class Solution {
public:
    
    
    bool dfs(int i,int j,vector<vector<char>>&board,string &word,vector<vector<char>>&vis,int k){
        if(k==word.size()){
            return true; //gotemm
        }
        
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j]==1 || board[i][j]!=word[k]){
            return false;
        }
        
        vis[i][j]=1;
        bool ans=false;
        ans=ans | dfs(i+1,j,board,word,vis,k+1);
        ans=ans |dfs(i-1,j,board,word,vis,k+1);
        ans=ans | dfs(i,j+1,board,word,vis,k+1);
        ans=ans | dfs(i,j-1,board,word,vis,k+1);
        
        //backtrack
        vis[i][j]=0;
        
        return ans;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        
        //DFS + Backtrack f
        //Let's do the Harder DP list 
        
        //visit if no success then trackback siu
        int n=board.size();
        int m=board[0].size();
        
     
        
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(board[i][j]==word[0]){
                    vector<vector<char>>vis(n+1,vector<char>(m+1,-1));
                    if(dfs(i,j,board,word,vis,0)){
                        return true;
                    }
                }
            }
        }
        
        return false; //sEd \U0001f614
        
        
    }
};