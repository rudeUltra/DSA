class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int res=1;
        int count=0;
        int left=0;
        int right=0;
        int n=nums.size();
        while(right<n){
            res=res*nums[right];
            while(res>=k){
                res=res/nums[left++];
            }
            count=count+(right-left)+1;
            right++;
        }
        return count;
    }
};