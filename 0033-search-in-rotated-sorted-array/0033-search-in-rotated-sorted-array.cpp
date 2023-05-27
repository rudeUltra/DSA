class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            
            if(nums[mid]>=nums[low]){
                //left part is sorted siuu
                if(target>=nums[low] && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                //right part is sorted check there siu 
                //remembeer BS always works for the sorted area only hM
                if(target<=nums[high] && target>nums[mid]){
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