class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int isIncreasing=1;
        int isDecreasing=1;
        for(int i=0;i<n-1;++i){
            if(nums[i]>nums[i+1]){
                isIncreasing=0;
            }
            if(nums[i]<nums[i+1]){
                isDecreasing=0;
            }
        }
        if(isIncreasing || isDecreasing){
            return true;
        }
        return false;
    }
};