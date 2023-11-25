class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
           int n=nums.size();
        
        int low=0;
        int high=n-1;
        
        while(low<=high){
            
            
            while (low < high && nums[low] == nums[low + 1]) {
                low++;
            }
            while (low < high && nums[high] == nums[high - 1]) {
                high--;
            }
            int mid=(low+(high-low)/2); //integer overflow Big brain
            
            if(nums[mid]==target){
                return true;
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
        
        return false;
        
    }
    
};