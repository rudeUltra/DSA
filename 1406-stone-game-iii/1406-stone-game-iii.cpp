class Solution {
public:
    
    int dfs(int idx,vector<int>&stoneValue,vector<int>&dp){
        if(idx>=stoneValue.size()){
            return 0; //base case siu
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int sum=0;
        int ans=INT_MIN; //not 0 because of negative numbers siu
        
        for(int i=1;i<=3;++i){
            if(idx+i>stoneValue.size()){
                break;
            }
            sum=sum+stoneValue[idx+i-1]; //basically the score
            ans=max(ans,sum-dfs(idx+i,stoneValue,dp)); //score minus the next opponents max score siu
            
            //so basically at root we are doing Alice max score minus Bob max Score
        }
        
        return dp[idx]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,-1);
        
        int diff=dfs(0,stoneValue,dp);
        cout<<diff;
        if(diff>0){
            return "Alice";
        }
        else if(diff<0){
            return "Bob";
        }
        else{
            return "Tie";
        }
    }
};