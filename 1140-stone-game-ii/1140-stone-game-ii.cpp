class Solution {
public:
    
    int f(int idx,int m,vector<int>&piles,int flag,vector<vector<vector<int>>>&dp){
        if(idx>=piles.size()){
            return 0;
        }
        int ans=0;
        
        if(dp[flag][idx][m]!=-1){
            return dp[flag][idx][m]; //siu
        }
        
        if(flag==1){
            ans=-1;
        }
        else{
            ans=INT_MAX; //for min
        }
        int sum=0;
        for(int x=1;x<=2*m;++x){
            if(idx+x>piles.size()){
                break; //out of bound
            }
            sum+=piles[idx+x-1]; //0 based indexing siu
            
            if(flag){
                //remember not to calculate bob's score
                ans=max(ans,sum+f(x+idx,max(m,x),piles,!flag,dp));
            }
            else{
                ans=min(ans,f(x+idx,max(m,x),piles,!flag,dp)); //bobs perspective if he gets alice score he obvs wants to minimize it so that alice gets less score automaticaly it mean bob gets more
                
                //we have to assume both players play optimally not just ALice
            }
        }
        
        return dp[flag][idx][m]=ans;
        
    }
    
    
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        //flag 1 means alice turn
        return f(0,1,piles,1,dp);
        
    }
};