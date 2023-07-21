class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        
        if(n==1){
            return 1;
        }
        vector<int>ways(n,1);
        int mx=INT_MIN;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        ways[i]=ways[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        //same lenght lIS hm
                        ways[i]+=ways[j];
                    }
                }
            }
            mx=max(mx,dp[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;++i){
            if(dp[i]==mx){
                ans+=ways[i];
            }
        }
        
        return ans;
    }
};