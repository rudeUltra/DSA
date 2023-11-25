class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = {nums[0]};
        for (int i = 1; i < n; i++) {
            prefix.push_back(prefix[i - 1] + nums[i]);
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int leftSum = prefix[i] - nums[i];
            int rightSum = prefix[n - 1] - prefix[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftTotal = leftCount * nums[i] - leftSum;
            int rightTotal = rightSum - rightCount * nums[i];
            
            ans.push_back(leftTotal + rightTotal);
        }
        
        return ans;
    }
};