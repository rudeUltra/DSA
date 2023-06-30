class Solution {
public:
    
    int f(int idx,int k,vector<int>&arr,vector<int>&dp){
        if(idx>=arr.size()){
            return 0; //siu
        }
        int ans=INT_MIN;
        int mx=INT_MIN;
        int n=arr.size();
        int len=0;
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        //at every index partition siu
        for(int i=idx;i<min(idx+k,n);++i){
            //cool trick ngl xD
            mx=max(mx,arr[i]);
            len++; //diff for each subarray xD cant do i+1.. 
            int temp=f(i+1,k,arr,dp)+(mx*len);
            ans=max(ans,temp);
        }
        
        return dp[idx]=ans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        
        return f(0,k,arr,dp);
    }
};