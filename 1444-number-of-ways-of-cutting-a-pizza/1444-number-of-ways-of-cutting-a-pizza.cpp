class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int j,int k,vector<string>&pizza,vector<vector<int>>&prefix,vector<vector<vector<int>>>&dp){
        
       
        if(prefix[i][j]==0){
            return 0; //no more apples below bruh condition faileD
        }
        if(k==0){
            return 1; //k-1 cuts done so fuckoFF
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        
        //horizontal cuts
        int horizontal=0;
        for(int x=i+1;x<pizza.size();++x){
            //cuts can be at any pos remember even empty ones Hmm
            if(prefix[i][j]-prefix[x][j]>0){
                horizontal=(horizontal%mod)+f(x,j,k-1,pizza,prefix,dp)%(mod);
            }
            
        }
        
        int vertical=0;
        for(int y=j+1;y<pizza[0].size();++y){
            if(prefix[i][j]-prefix[i][y]>0){
                //there are some apples between sIu so 2 cuts will have atleast 1 apple in between :)
                vertical=(vertical%mod)+f(i,y,k-1,pizza,prefix,dp)%(mod);
            }
        }
        
        return dp[i][j][k]=horizontal+vertical;
    }
    int ways(vector<string>& pizza, int k) {
        vector<vector<int>>prefix(pizza.size()+1,vector<int>(pizza[0].size()+1,0));
        vector<vector<vector<int>>>dp(pizza.size()+1,vector<vector<int>>(pizza[0].size()+1,vector<int>(k+1,-1)));
        
        //calculating prefix sum siu
        
        int n=pizza.size();
        int m=pizza[0].size();
        
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                prefix[i][j]=prefix[i][j+1]+prefix[i+1][j]-prefix[i+1][j+1];
                if(pizza[i][j]=='A'){
                    prefix[i][j]++; //count of apples siu
                }
            }
        }
        
        return f(0,0,k-1,pizza,prefix,dp);
        
        
    }
};