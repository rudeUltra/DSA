class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(sum<nums[i]){
                sum=nums[i];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};