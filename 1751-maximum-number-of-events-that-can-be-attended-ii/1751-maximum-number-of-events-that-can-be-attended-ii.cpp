class Solution {
public:
    
    
    int f(int idx,vector<vector<int>>& events,int prev,int k,vector<vector<int>>&dp){
        
        if(idx>=events.size()){
            return 0;
        }
        
        if(k==0){
            return 0;
        }
        
       
        if(events[idx][0]<=prev){
            return f(idx+1,events,prev,k,dp);
        }
         if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
      
        
        //if we choose then set prev ok
        
        int notpick=f(idx+1,events,prev,k,dp)+0;
        int pick=-99;
        
        if(events[idx][0]>prev){
            pick=f(idx+1,events,events[idx][1],k-1,dp)+events[idx][2];
        }
        
        
        return dp[idx][k]=max(pick,notpick);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        
        
       
        
        return f(0,events,-1,k,dp);
    }
};