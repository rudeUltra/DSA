class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size(), sum = 0, i = 0;
        vector<int> ans(n, -1);
        if(n < 2 * k) return ans;
        if(!k) return nums;
        
        int p = k * 2 + 1;
        for(int j=0; j<n; j++) {
            sum += nums[j];
            if(j - i + 1 == p) {
                ans[j - k] = sum / p;
                sum -= nums[i++];
            }
        }
        return ans;
    }
};