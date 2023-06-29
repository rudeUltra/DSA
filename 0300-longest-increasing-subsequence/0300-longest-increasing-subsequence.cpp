class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //LETS try bottom up siu
        int n=nums.size();
        vector<int>dp(n,1); //initially 1 size xD
        int mx=dp[0];
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                   
                }
                 mx=max(mx,dp[i]);
            }
        }
        return mx;
    }
};