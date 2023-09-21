class Solution {
public:
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j){
            return 0; //NO more balloons sed
        }
        int ans=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=i;k<=j;++k){
            //Cut
            int cost=nums[i-1]*nums[k]*nums[j+1];
            int temp=f(i,k-1,nums,dp)+f(k+1,j,nums,dp)+cost;
            ans=max(ans,temp);
        }
        
        return dp[i][j]=ans;
    }
    
    
    int maxCoins(vector<int>& nums) {
        //for easy and creating Indepented subproblems imagine u are bursting the current balloon last siu
        int n=nums.size();
        nums.push_back(1); //boundary
        nums.insert(nums.begin(),1);
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        
        return f(1,n,nums,dp);
    }
};