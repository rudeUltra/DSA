class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 1;
        }
        vector<int>lis(n,1);
        int ans=0;
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    lis[i]=max(lis[i],1+lis[j]);
                }
            }
            ans=max(ans,lis[i]);
        }
        
        return ans;
    }
};