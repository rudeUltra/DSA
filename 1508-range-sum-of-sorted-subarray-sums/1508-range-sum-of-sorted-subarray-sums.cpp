class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sums((n*(n+1))/2);
        int k=0;
        const int mod=1e9+7;
        for(int i=0;i<n;++i){
            int sum=0; //sum for that subarray Noice
            for(int j=i;j<n;++j){
                sum+=nums[j];
                sums[k++]=sum;
            }
        }
        
        sort(sums.begin(),sums.end());
        int ans=0;
        //Debug Noice
        for(int i=left-1;i<right;++i){
            ans+=sums[i];
            ans=ans%mod;
        }
        
        return ans;
    }
};