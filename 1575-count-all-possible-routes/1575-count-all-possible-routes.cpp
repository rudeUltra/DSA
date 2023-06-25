class Solution {
public:
    int mod=1000000007;
    int f(int curr,int finish,vector<int>&locations,int fuel,vector<vector<int>>&dp){
        if(fuel<0){
            return 0; //siu
        }
        
        if(dp[curr][fuel]!=-1){
            //starting with this index and with this amount of fuel siu
            return dp[curr][fuel];
        }
        int ans=0;
        if(curr==finish){
            ans=1; //base case siu
        }
        
        for(int i=0;i<locations.size();++i){
            if(i!=curr){
                ans=(ans+f(i,finish,locations,fuel-abs(locations[curr]-locations[i]),dp))%(mod);
                //count all ways siu
            }
        }
        
        return dp[curr][fuel]=ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        //wow man we got it siu
        //special base case scenario dont return 1 if hit target because loop hMMmMM
        vector<vector<int>>dp(locations.size()+1,vector<int>(fuel+1,-1));
        return f(start,finish,locations,fuel,dp);
        //bc start and location are indexes betichod
    }
};