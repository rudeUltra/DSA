class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            cout<<nums[mid]<<" ";
            if(mid>0 && nums[mid]<nums[mid-1]){
                //pivot found siu
                return nums[mid];
            }
            
            if(nums[mid]>nums[low] && nums[mid]<nums[high]){
                //sorted array bc!
                return nums[low];
            }
            
            
            else if(nums[high]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<low<<" "<<high;
        return nums[low];
    }
};