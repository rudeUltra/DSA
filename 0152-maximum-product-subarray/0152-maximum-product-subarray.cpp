class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mx=nums[0];
        int mn=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;++i){
            int temp=mx;
            int z=max(nums[i]*mn,nums[i]*mx);
            mx=max(nums[i],z);
            int k=min(nums[i]*temp,nums[i]*mn);
            mn=min(nums[i],k);
            ans=max(mx,ans);
        }
        
        return ans;
    }
};