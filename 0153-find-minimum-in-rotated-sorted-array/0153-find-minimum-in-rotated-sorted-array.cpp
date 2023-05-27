class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        if(n==1){
            nums[0]; //basically pivot finding siu
        }
        if(nums[low]<nums[high]){
            //rotated n times already sorted so
            return nums[0];
        }
        while(low<=high){
            int mid=low+(high-low)/2; //integer overflow
            if(mid>0 && nums[mid-1]>nums[mid]){
                //found the pivot siu
                return nums[mid];
            }
            if(nums[mid]>=nums[low] && nums[mid]>=nums[high]){
                low=mid+1; //search in the unsorted array siu pls make sure right part is also unsorted otherwise edge cases siu
            }
            else{
                high=mid-1; 
            }
        }
        return nums[0]; //will never hit but k
    }
};