class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2)
            return n;
        int rIndex = 1;
        for(int i = 2; i < n; i++)
        {
            int currentNumber = nums[i];
            if(currentNumber == nums[rIndex] && currentNumber == nums[rIndex - 1])
                continue;
            nums[++rIndex] = nums[i];
        }
        return rIndex + 1;
    }
};