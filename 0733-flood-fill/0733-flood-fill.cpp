class Solution {
public:
    
    void dfs(vector<vector<int>>& image,int i,int j,int prev,int newcolor){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=prev){
            return;
        }
        //only change the prev color we cant change other colors sed
        image[i][j]=newcolor;
        
        dfs(image,i+1,j,prev,newcolor);
        dfs(image,i-1,j,prev,newcolor);
        dfs(image,i,j+1,prev,newcolor);
        dfs(image,i,j-1,prev,newcolor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image; //already colored siu
        }
        
        dfs(image,sr,sc,image[sr][sc],color);
        
        return image;
    }
};