class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //big ass question xD but i like it so les go siu
    
        int n=matrix.size();
        int m=matrix[0].size();
        
        int rstart,rend,cstart,cend;
        rstart=0;
        rend=n-1;
        cstart=0;
        cend=m-1;
        
        vector<int>ans;
        
        while(rstart<n && rend>=0 && cstart<m && cend>=0){
            //top row siu
            
            
            for(int i=cstart;i<=cend;++i){
                ans.push_back(matrix[rstart][i]);
            }
            rstart++;
            
            if(rstart>rend){
                break;
            }
            
            
            //right col
            
            
            
            for(int i=rstart;i<=rend;++i){
                ans.push_back(matrix[i][cend]);
            }
            cend--;
            
            if(cstart>cend){
                break;
            }
            
            
           
            //bottom row 
            
            for(int i=cend;i>=cstart;--i){
                ans.push_back(matrix[rend][i]);
            }
            rend--;
            
             if(rstart>rend){
                break;
            }
            
            
            
             
            
            //left col
            for(int i=rend;i>=rstart;--i){
                ans.push_back(matrix[i][cstart]);
            }
            cstart++;
            
            if(cstart>cend){
                break;
            }
        }
        
        return ans;
    }
};