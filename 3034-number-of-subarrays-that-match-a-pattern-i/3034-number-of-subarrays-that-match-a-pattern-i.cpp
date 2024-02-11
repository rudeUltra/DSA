class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size(), count = 0;
        for(int i = 0 ; i + m < n ; i++){
            int j = 0;
            for( ; j < m ; j++){
                if(pattern[j] == 1){
                    if(nums[i + j + 1] <= nums[i + j])
                        break;
                }
                else if(pattern[j] == 0){
                    if(nums[i + j + 1] != nums[i + j])
                        break;
                }
                else{
                    if(nums[i + j + 1] >= nums[i + j])
                        break;
                }
            }
            if(j == m)
                count++;
        }
        return count;
    }
};