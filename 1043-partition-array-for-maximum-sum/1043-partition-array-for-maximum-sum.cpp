class Solution {
public:
    int f(int idx,int k,vector<int>&arr,vector<int>&dp){
        if(idx==arr.size()){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int mx=INT_MIN;
        int ans=INT_MIN;
        int length=0;
        int n=arr.size();
        for(int j=idx;j<min(idx+k,n);++j){
            length++;
            mx=max(mx,arr[j]);
            int sum=f(j+1,k,arr,dp)+(length*mx);
            ans=max(sum,ans);
        }
        
        return dp[idx]=ans;
        
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(0,k,arr,dp);
    }
};