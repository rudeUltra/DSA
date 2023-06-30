class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1); // for out of bounds condition
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,nums,dp);
    }
     int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res=INT_MIN;
        for(int k=i;k<=j;k++){
            
            int ans=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums,dp)+f(k+1,j,nums,dp);
            res=max(res,ans);
        }
        
        return dp[i][j]=res;
    }
    
   
    
};