class Solution {
public:
    
   
    
    
    int longestArithSeqLength(vector<int>& nums) {
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(2000,1)); //LIS Is 1 for single element
        //LIS pattern just for each I keep a diff to match 
        int ans=0;
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                //siu
                int diff=nums[i]-nums[j]+502; //for negative number sed
                //check if this diff occurs or not HMM
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1); //initally we can take any 2 starting siu
                ans=max(ans,dp[i][diff]);
                
            }
        }
        return ans;
        
    }
};