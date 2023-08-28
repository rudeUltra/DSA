class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>ds(n);
        //initialize
        string s(n,'.');
        for(int i=0;i<n;++i){
            ds[i]=s;
        }
        dfs(0,n,ds,ans);
        return ans;
    }
    bool issafe(int row,int col,vector<string>ds){
        //check for upper right 
        int i=row;
        int j=col;
        while(i>=0 && j>=0){
            if(ds[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;
        //check for horizontal siuu
        while(j>=0){
            if(ds[row][j]=='Q'){
                return false;
            }
            j--;
        }
        
        //check for lower right
        
        i=row;
        j=col;
        
        while(i<ds.size() && j>=0){
            if(ds[i][j]=='Q'){
                return false;
            }
            ++i;
            j--;
        }
        return true;
    }
    void dfs(int col,int n,vector<string>&ds,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(ds);
            return;
        }
        
        for(int row=0;row<n;++row){
            if(issafe(row,col,ds)){
                ds[row][col]='Q';
                dfs(col+1,n,ds,ans);
                ds[row][col]='.';
            }
        }
    }
};