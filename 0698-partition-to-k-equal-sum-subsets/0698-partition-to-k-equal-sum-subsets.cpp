class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //5 per Day ? not good.
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp((1<<16)+2,-1);
        
        dp[0]=0;
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        
        if(sum%k!=0){
            return false;
        }
        
        int target=sum/k; //bucket size basically
        
        for(int mask=0;mask<(1<<n);++mask){
            if(dp[mask]==-1){
                //not explored so fuck off
                continue;
            }
            for(int i=0;i<n;++i){
                if(!(mask&(1<<i)) && dp[mask]+nums[i]<=target){
                    //not picked and less than equal to target so possible hm
                    
                    dp[mask | (1<<i)]=(dp[mask]+nums[i])%target;
                }
            }
        }
        
        return dp[(1<<n)-1]==0;
    }
};