class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //lets check low and mid value HMM
        int n=nums.size(); //binary search obvs
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                //found siu
                return mid;
            }
            else if(nums[mid]>target){
                //kam karo bhai
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};