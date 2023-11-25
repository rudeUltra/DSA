class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Point is to keep searching in Sorted part of the array siu using low and high pointers hm
        
        int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=(low+(high-low)/2); //integer overflow Big brain
            
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid]>=nums[low]){
                //left part sorted
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                //Right part is sorted hm
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        
        return -1;
    }
};