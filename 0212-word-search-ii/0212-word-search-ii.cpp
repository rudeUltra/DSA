class Solution {
    struct node{
        char c;
        int ends;
        string word; //to directly push the ans
        node *child[26];
        
    };
    struct node*getnode(char c){
        //constructor to initialize
        node *newnode=new node;
        newnode->c=c;
        newnode->ends=0;
        newnode->word="";
        for(int i=0;i<26;++i){
            newnode->child[i]=NULL;
        }
        return newnode;
    }
    node *root=getnode('/'); //root value
    
    void insert(string s){
        node *curr=root;
        int index,i=0;
        while(i<s.size()){
            index=s[i]-'a'; //0-26 indexing
            if(curr->child[index]==NULL){
                curr->child[index]=getnode(s[i]);
            }
            curr=curr->child[index];
            ++i;
        }
        //word completed 
        curr->ends++;
        curr->word=s;
    }
public:
    void dfs(int i,int j,vector<vector<char>>&board,vector<string>&ans,node *curr){
        int index=board[i][j]-'a';
        if(board[i][j]=='$'|| curr->child[index]==NULL){
            return; //if a word starting from this char doesnt exist or this char already been visited siu
        }
        curr=curr->child[index];
        if(curr->ends>0){
            ans.push_back(curr->word); //entire words exists siu
            curr->ends--; //we dont wanna use the same word again no duplicates
        }
        char ch=board[i][j];
        board[i][j]='$'; //visited
        //checking out of bounds condition siu
        
        if(i>0){
            dfs(i-1,j,board,ans,curr);
        }
        if(i<board.size()-1){
            dfs(i+1,j,board,ans,curr);
        }
        if(j>0){
            dfs(i,j-1,board,ans,curr);
        }
        if(j<board[0].size()-1){
            dfs(i,j+1,board,ans,curr);
        }
        //backtrack unmark it
        board[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //siu DFS+TRIE
        int n=board.size();
        int m=board[0].size();
        vector<string>ans;
        
        for(int i=0;i<words.size();++i){
            insert(words[i]); //insert all words onto the trie siu for betterr T.C 
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                //traversing through the grid/matrix
                dfs(i,j,board,ans,root);
                
            }
        }
        return ans;
    }
};