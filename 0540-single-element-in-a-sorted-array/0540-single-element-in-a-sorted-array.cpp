class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        
        //it is guaranteed that a single element occurs siu
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(mid>0 && nums[mid-1]!=nums[mid] && mid<n && nums[mid]!=nums[mid+1]){
                //siu found
                return nums[mid];
            }
            
            if(mid>0 && nums[mid-1]!=nums[mid]){
                //first element hm
                if((mid+1)%2==1){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            
            else{
                //second element
                if((mid+1)%2==0){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        
        return nums[low];
        
    }
};