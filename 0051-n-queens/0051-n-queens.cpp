class Solution {
public:
    bool valid(int row,int col,vector<string>ds){
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
    void f(int col,int n,vector<vector<string>>&ans,vector<string>&temp){
       if(col==n){
           ans.push_back(temp);
           return;
       }
        
        for(int i=0;i<n;++i){
            //rOW placement
            if(valid(i,col,temp)){
                temp[i][col]='Q';
                f(col+1,n,ans,temp);
                temp[i][col]='.'; //backtrack
            }
        }
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp;
        string ds(n,'.');
        for(int i=0;i<n;++i){
            temp.push_back(ds);
        }
        
        f(0,n,ans,temp);
        
        return ans;
        
        
    }
};